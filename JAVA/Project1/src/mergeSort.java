import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class mergeSort {
	public static void main(String[] argz) throws FileNotFoundException,
			UnsupportedEncodingException {
		String filename1;
		System.out.println("Please enter the name of the first input file:");
		Scanner sc = new Scanner(System.in);
		filename1 = sc.next();
		String filename2;
		System.out.println("Please enter the name of the second input file:");
		filename2 = sc.next();
		String outputFilename;
		System.out.println("Please enter the name of an output file:");
		outputFilename = sc.next();
		sc.close();
		// Make sure each file is sorted before proceeding with the program.
		boolean isSorted = checkSorted(filename1);
		if (!isSorted) {
			System.out.println("The first input file is not sorted!");
			return;
		}
		isSorted = checkSorted(filename2);
		if (!isSorted) {
			System.out.println("The second input file is not sorted!");
			return;
		}
		Scanner first = new Scanner(new File(filename1));
		Scanner second = new Scanner(new File(filename2));
		
		Integer a = 0;
		Integer b = 0;
		PrintWriter outStream;
		FileOutputStream fos = new FileOutputStream(outputFilename);
		OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");
		outStream = new PrintWriter(out);
		outStream.flush();
		int outputCount = 0;
		// print numbers from both input files to output file in order
		a = first.nextInt();
		b = second.nextInt();
		while(first.hasNextInt() && second.hasNextInt()){
			if (a <= b) {
				outStream.print(a + " ");
				outputCount++;
				a = first.nextInt();
				
			} else {
				outStream.print(b + " ");
				outputCount++;
				b = second.nextInt();
				
			}
		}
		
		if(!first.hasNextInt()){
			outStream.print(a + " ");
			outputCount++;
			
			// print any remaining values from second input file to output file
			while (second.hasNextInt()) {
				outStream.print(b + " ");
				outputCount++;
				b = second.nextInt();
			}
			outStream.print(b + " ");
			outputCount++;
		}
		else if(!second.hasNextInt()){
			outStream.print(b + " ");
			outputCount++;
			
			// print any remaining values from first input file to output file
			while (first.hasNextInt()) {
				outStream.print(a + " ");
				outputCount++;
				a = first.nextInt();
			}
			outStream.print(a + " ");
			outputCount++;
		}
		
		
	
		
		
	
				
		System.out.println("Have outputted " + outputCount + " numbers.");
		first.close();
		second.close();
//		outputFile.close();
		outStream.close();
	}

	public static boolean checkSorted(String file) throws FileNotFoundException {
		Scanner input = new Scanner(new File(file));
		int x = input.nextInt();
		int y;
		while (input.hasNext()) {
			y = input.nextInt();
			if (y < x)
				return false;
			x = y;
		}
		input.close();
	
		return true;
	}
}