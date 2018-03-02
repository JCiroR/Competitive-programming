import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
 
// 787  Maximum sub-sequence product 
// Wrong approach, still AC, ugly code
class Main
{
    static BigInteger productOf(String [] values, int from, int to) {
        if(from < 0) from = 0;
        if(to >= values.length) to = values.length - 1;
        String stop = "-999999";

        while(values[from].equals("") && from < values.length) from++;
            

        BigInteger product = new BigInteger(values[from]);
        for(int i = from + 1; i <= to; i++) {
            if(values[i].equals(stop) || values[i].equals("")) continue; 
            product =  product.multiply(new BigInteger(values[i]));
        }
        return product;
    }

    public static void main(String[] args) throws IOException
    {
 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String stop = "-999999";
        String line = "";
        BigInteger zero = new BigInteger("0");

        // Leer hasta EOF
        while((line = br.readLine()) != null) { 
            String [] sequences = line.split(" 0");
            BigInteger maxProduct = BigInteger.valueOf(-999999);
            BigInteger curr = BigInteger.valueOf(-999999);

            for(int i = 0; i < sequences.length; i++) {
                String [] values = sequences[i].split(" ");

                //Contar negativos
                int firstNeg = -1, lastNeg = -1, negCount = 0;
                for(int j = 0; j < values.length; j++) {
                    if(values[j].equals(stop)) continue;
                    if(values[j].startsWith("-")) {
                        negCount++;
                        if(firstNeg == -1) firstNeg = j;
                        if(firstNeg != -1) lastNeg = j;
                    }
                }

                if(negCount % 2 == 0) curr = productOf(values, 0, values.length - 1);
                else {
                    if(values.length == 1) curr = new BigInteger(values[0]);
                    else if(lastNeg != -1) {
                        BigInteger op1 = productOf(values, 0, lastNeg - 1);
                        BigInteger op2 = productOf(values, firstNeg + 1, values.length - 1);
                        curr = op1.max(op2);
                    } else {
                        BigInteger op1 = productOf(values, firstNeg + 1, values.length - 1);
                        BigInteger op2 = productOf(values, 0, firstNeg - 1);
                        curr = op1.max(op2);
                        curr = curr.max(new BigInteger(values[firstNeg]));
                    }
                }
                maxProduct = maxProduct.max(curr);
            }
            if(maxProduct.compareTo(BigInteger.ZERO) == - 1 && sequences.length > 1 ) System.out.println("0");
            else System.out.println(maxProduct);
        }
    }
}