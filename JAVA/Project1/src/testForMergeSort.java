import java.awt.List;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

public class testForMergeSort {
	public static void main(String[] argz) throws FileNotFoundException, UnsupportedEncodingException{
		String concatFile = argz[0];
		String mergedFile = argz[1];
		
		System.out.println("outputFile: " + concatFile);
		System.out.println("mergedFile: " + mergedFile);
		
		ArrayList<Integer> combinedList = new ArrayList<Integer>();
		Scanner cf = new Scanner(new File(concatFile));
		int n = 0;
		while(cf.hasNextInt()){
			n = cf.nextInt();
			combinedList.add(n);
		}
		cf.close();
		System.out.println("number of ints in combinedList = " + combinedList.size());
		System.out.println("combinedList: " + combinedList);
		
		//NOW VERIFY THAT THE VALUES IN THE MERGED OUTPUT FILE ARE IN THE ARRAY LIST CREATED FROM THE CONCAT OUTPUT FILE.
		Scanner mf = new Scanner(new File(mergedFile));
		Integer t = 0;
		while(mf.hasNextInt()){
			t = mf.nextInt();
			if(!(combinedList.contains(t))){
				System.out.println("TEST FAILED: mergedFile is not the same as concatFile!");
				System.out.println("The culprit is: " + t);
				return;
			}
			else{//if combinedList does contain t, remove that instance of t in the list
				System.out.println(t + " was verified just fine.");
				combinedList.remove(combinedList.indexOf(t));
				System.out.println("combinedList: " + combinedList);
			}
		}
		System.out.println("TEST PASSED: mergedFile is the same as concatFile!");
		
		mf.close();
	}
}
