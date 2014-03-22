import java.awt.List;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

public class concatenateFiles{
	public static void main(String[] argz) throws FileNotFoundException, UnsupportedEncodingException{
		String file1 = argz[0];
		String file2 = argz[1];
		String concatFile = argz[2];
		
		System.out.println("file1: " + file1);
		System.out.println("file2: " + file2);
		System.out.println("outputFile: " + concatFile);
		
		//First concatenate the two input files, data1.txt and data2.txt
		Scanner s1 = new Scanner(new File(file1));
		Scanner s2 = new Scanner(new File(file2));
		
		PrintWriter outStream;
		FileOutputStream fos = new FileOutputStream(concatFile);
		OutputStreamWriter out = new OutputStreamWriter(fos, "UTF-8");
		outStream = new PrintWriter(out);
		outStream.flush();
		
		int x = 0;
		while(s1.hasNextInt()){
			x = s1.nextInt();
			//System.out.println("x=" + x);
			outStream.print(x + " ");
		}
//		outStream.println(" "); //space needed before next list!!!
		
		int y = 0;
		while(s2.hasNextInt()){
			y = s2.nextInt();
			//System.out.println("y=" + y);
			outStream.print(y + " ");
		}
		
		s1.close();
		s2.close();
		//DON'T FORGET TO CLOSE THE OUTPUT STREAM!!!!
		outStream.close();
		
		System.out.println("Finished concatenating the two files.");
	}
}