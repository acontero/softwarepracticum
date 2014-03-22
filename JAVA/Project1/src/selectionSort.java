import java.io.*;
import java.lang.Object;
import java.util.Scanner;

public class selectionSort {

	public static void main(String[] argz) throws FileNotFoundException,
			UnsupportedEncodingException {
		String filename;
		
		System.out.println("Please enter the name of the input file:");
		Scanner sc = new Scanner(System.in);
		filename = sc.next();
		String outputFilename;
		System.out.println("Please enter the name of an output file:");
		outputFilename = sc.next();

		Scanner input = new Scanner(new File(filename));
		int token = input.nextInt();
		int dataCount = 1;
		while (input.hasNextInt()) {
			token = input.nextInt();
			dataCount++;
		}
		System.out.println("Num of integers in file " + filename + " = "
				+ dataCount);
		sc.close(); // closes System.in stream
		input.close(); // closes file stream
		
		//DYNAMIC ALLOCATION!
		int[] dataSorted = new int[dataCount];
		Scanner s = new Scanner(new File(filename));
		int count = 0;
		token = s.nextInt();
		System.out.println("First token is: " + token);
		dataSorted[count] = token;
		count++;
		System.out.println("Saved to array as: " + dataSorted[0]);
		while (s.hasNextInt()) {
			token = s.nextInt();
			dataSorted[count] = token;
			count++;
		}
		System.out.println("Saved to array as: " + dataSorted[0]);
		int startIndex = 0;
		int endIndex = dataCount - 1;
		int minIndex;
		int walkerIndex;
		int temp;
		while (!(startIndex >= endIndex)) {
			minIndex = startIndex;
			walkerIndex = startIndex + 1;
			while (!(walkerIndex > endIndex)) {
				if (dataSorted[walkerIndex] < dataSorted[minIndex]) {
					minIndex = walkerIndex;
				}
				walkerIndex++;
			}
			temp = dataSorted[startIndex];
			dataSorted[startIndex] = dataSorted[minIndex];
			dataSorted[minIndex] = temp;
			startIndex++;
		}
		System.out.println("After sorting, first element is: " + dataSorted[0]);
		// Didn't work when I tried to ask user for output file name at this
		// point, it
		// kept moving onto the next bit of code, without giving user chance to
		// type anything in.

		PrintWriter outStream;
		FileOutputStream fos = new FileOutputStream(outputFilename);
		OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");
		outStream = new PrintWriter(out);
		outStream.flush();
		for (int i = 0; i < dataSorted.length; i++) {
			outStream.print(dataSorted[i] + " ");
		}
		// outStream.println(s);
		outStream.close();
		
	}
}