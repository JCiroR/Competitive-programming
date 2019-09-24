
import java.math.BigInteger;

public class CRT {
	public static void main(String [] args) {
		Number.init();
		Number x = new Number(120);
		Number y = new Number(20);
		Number xy = x.multiply(y);
		System.out.println(xy.bigIntegerValue(false));
	}
}

class Number {
	static final int SZ = 100;
	static int pr[] = new int[SZ];
	static int r[][] = new int[SZ][SZ];
	
	int a[] = new int[SZ];

	static void init() {
	    for (int x = 1000 * 1000 * 1000, i = 0; i < SZ; ++x)
	        if (BigInteger.valueOf(x).isProbablePrime(100))
	            pr[i++] = x;
	
	    for (int i = 0; i < SZ; ++i)
	        for (int j = i + 1; j < SZ; ++j)
	            r[i][j] =
	                BigInteger.valueOf(pr[i]).modInverse(BigInteger.valueOf(pr[j])).intValue();
	}
	
	public Number() {
	}

	public Number(int n) {
		for (int i = 0; i < SZ; ++i)
			a[i] = n % pr[i];
	}

	public Number(BigInteger n) {
		for (int i = 0; i < SZ; ++i)
			a[i] = n.mod(BigInteger.valueOf(pr[i])).intValue();
	}

	public Number add(Number n) {
		Number result = new Number();
		for (int i = 0; i < SZ; ++i)
			result.a[i] = (a[i] + n.a[i]) % pr[i];
		return result;
	}

	public Number subtract(Number n) {
		Number result = new Number();
		for (int i = 0; i < SZ; ++i)
			result.a[i] = (a[i] - n.a[i] + pr[i]) % pr[i];
		return result;
	}

	public Number multiply(Number n) {
		Number result = new Number();
		for (int i = 0; i < SZ; ++i)
			result.a[i] = (int)((a[i] * 1l * n.a[i]) % pr[i]);
		return result;
	}

	public BigInteger bigIntegerValue(boolean can_be_negative) {
		BigInteger result = BigInteger.ZERO, mult = BigInteger.ONE;
		int x[] = new int[SZ];
		for (int i = 0; i < SZ; ++i) {
			x[i] = a[i];
			for (int j = 0; j < i; ++j) {
				long cur = (x[i] - x[j]) * 1l * r[j][i];
				x[i] = (int)((cur % pr[i] + pr[i]) % pr[i]);
			}
			result = result.add(mult.multiply(BigInteger.valueOf(x[i])));
			mult = mult.multiply(BigInteger.valueOf(pr[i]));
		}

		if (can_be_negative)
			if (result.compareTo(mult.shiftRight(1)) >= 0)
				result = result.subtract(mult);

		return result;
	}
}
