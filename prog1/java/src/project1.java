/*
 File Name: project1.java
 Author: Perry, Ethan
 Course: CSC 402
 Date: 02/08/16
*/

import java.util.ArrayList;
import java.util.Random;

public class project1{
	
	public static void main(String args[]){
		
			final int SIZE = 1000;
			int[] array1 = new int[SIZE] ;
			ArrayList<Integer> array2 = new ArrayList<Integer>();
			Random rand = new Random();
			
			for (int i = 0;i<SIZE;i++) {	
				array1[i] = rand.nextInt(32767);
				array2.add(rand.nextInt(32767));	
			}
			
			long startTime1 = System.nanoTime();
			sortNative(array1);
			long endTime1 = System.nanoTime();

			long startTime2 = System.nanoTime();
			sortFixed(array2);
			long endTime2 = System.nanoTime();
			
			long duration1 = (endTime1 - startTime1)/1000000;
			long duration2 = (endTime2 - startTime2)/1000000;
			
			System.out.println("Java: Sorting the native array took " + duration1 + "ms, and sorting the fixed array took " + duration2 + "ms." + " Size was " + SIZE + ".");
			
	}
	
	public static void sortNative(int[] ar){
		
		 int i, j, first, temp;  
	     for ( i = ar.length - 1; i > 0; i-- )  
	     {
	          first = 0;   //initialize to subscript of first element
	          for(j = 1; j <= i; j ++)   //locate smallest element between positions 1 and i.
	          {
	               if( ar[ j ] < ar[ first ] )         
	                 first = j;
	          }
	          temp = ar[ first ];   //swap smallest found with element in position i.
	          ar[ first ] = ar[ i ];
	          ar[ i ] = temp; 
	      }  
		
	}
	
	public static void sortFixed(ArrayList<Integer> ar){
		
		int i, j, first, temp;
		for ( i = ar.size() - 1; i > 0; i-- )  
	     {
	          first = 0;   //initialize to subscript of first element
	          for(j = 1; j <= i; j ++)   //locate smallest element between positions 1 and i.
	          {
	               if( ar.get(j) < ar.get(first))         
	                 first = j;
	          }
	          temp = ar.get(first);   //swap smallest found with element in position i.
	          ar.set(first, ar.get(i));
	          ar.set(i, temp);
	      }   

		
	}
	
}