import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int from = 1;
        int by = 2;
        int to = 3;
        bw.write((int)(Math.pow(2,N)-1) + "\n");
        Hanoi(from, by, to, N);
        bw.flush();
        bw.close();
        br.close();
    }

    public static void Hanoi(int from, int by, int to, int N) throws IOException {
        if(N == 1) {
            bw.write(from + " " + to + "\n");
            return;
        }
        Hanoi(from, to, by, N-1);
        bw.write(from + " " + to + "\n");
        Hanoi(by, from, to, N-1);
    }
}