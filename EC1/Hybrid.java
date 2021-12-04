package HybridSort;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class Hybrid {

    public static int counterHybrid = 0;
    public static int counterMerge = 0;
    public static final long MAX = 99999;

    static void printArray(int[] arr){
        for(int i=0; i < arr.length; i++){
            System.out.printf("%d ", arr[i]);
        }
        System.out.printf("\n");
    }


    static void insertionSort(int[] arr, int n, int m){
        int temp;
        if(n >= m) return;
        for(int i=n; i<=m ;i++){
            for(int j=i; j>n; j--){
                if(arr[j] < arr[j-1]){
                    temp = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = temp;
                    counterHybrid+=1;
                }
                else{
                    break;
                }
            }
        }
        return;
    }


    static void mergeSort(int[] arr, int n, int m){
        int mid = (n+m)/2;
        if(m-n <= 0){
            return;
        }
        mergeSort(arr, n, mid);
        mergeSort(arr, mid+1, m);
        merge(arr, n, m);
        return;
    }


    static void merge(int[] arr, int low, int high){
        if(low >= high) return;
        int[] tempArr = new int[high-low+1];
        int index = 0, i = low, j = 1 + (low + high)/2, mid = (low + high)/2;
        while(i <= mid && j <= high){
            counterHybrid+=1;
            counterMerge+=1;
            if(arr[i] < arr[j]){
                tempArr[index] = arr[i];
                i++;
            }
            else{
                tempArr[index] = arr[j];
                j++;
            }
            index++;
        }

        if(i > mid){
            while(j <= high){
                tempArr[index] = arr[j];
                index++;
                j++;
            }
        }
        else{
            while(i <= mid){
                tempArr[index] = arr[i];
                index++;
                i++;
            }
        }
        for(int k=0; k<index; k++){
            arr[low+k] = tempArr[k];
        }
        return;
    }


    static void hybridSort(int[] arr, int n, int m, int size, int S){
        int mid = (n+m)/2;
        if(m-n <= 0){
            return;
        }
        if(size < S){
            insertionSort(arr, n, m);
        }
        else {
            hybridSort(arr, n, mid, mid-n+1, S);
            hybridSort(arr, mid + 1, m, m - mid, S);
            merge(arr, n, m);
        }

        return;
    }


    public static void main(String[] args){
        Random rnd = new Random();
        int testSize=500;
        Map<Integer, Integer>bestThreshold = new HashMap<Integer, Integer>();
        for(int size=1; size<=testSize; size++){

            int[] array = new int[size];
            for(int i=0; i<array.length; i++){
                array[i] = Math.abs(rnd.nextInt() % 100);
            }

            int lowestThreshold=0;
            long shortestTime=MAX;

            for(int i=0; i< array.length; i++){
                int[] duplicateArray = array.clone();
                long startTime = System.nanoTime();
                hybridSort(duplicateArray, 0, size-1, size, i);
                long stopTime = System.nanoTime();

                if(stopTime-startTime < shortestTime){
                    shortestTime=stopTime-startTime;
                    lowestThreshold=i;
                }
            }
        //    System.out.println("Array Size: " + size + " runs fastest with threshold " + lowestThreshold + " at time " + shortestTime);
            bestThreshold.put(size, lowestThreshold);
        }
        for(int i=1; i<=testSize; i++){
            int[] array = new int[i];
            for(int j=0; j<array.length; j++){
                array[j] = Math.abs(rnd.nextInt());
            }
            int[] duplicateArray = array.clone();

            long startTime = System.nanoTime();
            mergeSort(array, 0, i-1);
            long stopTime = System.nanoTime();
            System.out.println("Merge Sort at size " + i + " takes " + (stopTime-startTime) + "s");

            startTime = System.nanoTime();
            hybridSort(duplicateArray, 0, i-1, i, bestThreshold.get(i));
            stopTime = System.nanoTime();
            System.out.println("Hybrid Sort at size " + i + " with threshold " + bestThreshold.get(i) + " takes " + (stopTime-startTime) + "s" );
        }


    }
}
