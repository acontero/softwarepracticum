import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class testForSorted {
	public static void main (String[] argz) throws FileNotFoundException{
		String file = argz[0];
		
		boolean isSorted = checkSorted(file);
		if (!isSorted) {
			System.out.println("TEST FAILED: The input file is not sorted!");
			return;                                                  
		}
		System.out.println("TEST PASSED: The input file is sorted!");
	}
	
	public static boolean checkSorted(String file) throws FileNotFoundException {
		Scanner input = new Scanner(new File(file));
		int x = input.nextInt();                            
		int y;
		while (input.hasNextInt()) {
			y = input.nextInt();
			if (y < x)
				return false;
			x = y;
		}
		input.close();
	
		return true;
	}
}


