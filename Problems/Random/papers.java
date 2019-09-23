import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Locale;

class papers {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String line;
			while((line = in.readLine())  != null) {
				BigDecimal p1x1, p1y1, p1x2, p1y2, p2x1, p2y1, p2x2, p2y2;
				String nums[] = line.split(" ");
				p1x1 = new BigDecimal(nums[0]);
				p1y1 = new BigDecimal(nums[1]);
				in.readLine();
				line = in.readLine();
				nums = line.split(" ");
				p1x2 = new BigDecimal(nums[0]);
				p1y2 = new BigDecimal(nums[1]);
				in.readLine();
				
				line = in.readLine();
				nums = line.split(" ");
				p2x1 = new BigDecimal(nums[0]);
				p2y1 = new BigDecimal(nums[1]);
				in.readLine();
				line = in.readLine();
				nums = line.split(" ");
				p2x2 = new BigDecimal(nums[0]);
				p2y2 = new BigDecimal(nums[1]);
				in.readLine();
				
				p1x1 = p1x1.add(p1x2);
				p1x1 = p1x1.divide(new BigDecimal("2"));
				p1y1 = p1y1.add(p1y2);
				p1y1 = p1y1.divide(new BigDecimal("2"));
				
				p2x1 = p2x1.add(p2x2);
				p2x1 = p2x1.divide(new BigDecimal("2"));
				p2y1 = p2y1.add(p2y2);
				p2y1 = p2y1.divide(new BigDecimal("2"));

				if(p1x1.compareTo(p2x1) == 0 && p1y1.compareTo(p2y1) == 0) {
					p2x1 = new BigDecimal("0");
					p2y1 = new BigDecimal("0");
				}
				
				double ans1, ans2, ans3, ans4;
				ans1 = p1x1.doubleValue();
				ans2 = p1y1.doubleValue();
				ans3 = p2x1.doubleValue();
				ans4 = p2y1.doubleValue();
				
				System.out.printf("YES %.5f %.5f %.5f %.5f\n", ans1, ans2, ans3, ans4);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}