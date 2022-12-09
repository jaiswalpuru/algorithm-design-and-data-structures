public class Main {
    public static void main(String[] args) {
        int[] arr = new int[]{10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        System.out.println("Element 13 found at index : " + ternarySearch(arr, 0, arr.length-1, 13));
        System.out.println("Element 45 found at index : " + ternarySearch(arr, 0, arr.length-1, 45));
    }

    public static int ternarySearch(int[] arr, int low, int high, int target) {
        if (low > high) return -1;
        int midOne = low + (high-low)/3;
        int midTwo = midOne + (high-low)/3;
        if (arr[midOne] == target) return midOne;
        if (arr[midTwo] == target) return midTwo;
        if (target < arr[midOne]) return ternarySearch(arr, low, midOne-1, target);
        else if (target > arr[midTwo]) return ternarySearch(arr, midTwo+1, high, target);
        else return ternarySearch(arr, midOne+1, midTwo-1, target);
    }
}


