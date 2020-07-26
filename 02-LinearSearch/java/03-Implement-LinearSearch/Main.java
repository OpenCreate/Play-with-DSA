public class Main {
  public static void main(String[] args) {
      int[] data = {22, 33, 15, 8, 79, 12, 90, 66, 5};

      int res = LinearSearch.search(data, 15);
      System.out.println(res);

      int res2 = LinearSearch.search(data, 1024);
      System.out.println(res2);
  }
}
