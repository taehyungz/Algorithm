import java.util.*;

class Solution {
    int[][] numberMap;
    public int[] solution(int rows, int columns, int[][] queries) {
        List<Integer> answer = new ArrayList<>();
        numberMap = new int[rows][columns];
        int number = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                numberMap[i][j] = number++;
            }
        }
        for (int[] query: queries) {
            int y1 = query[0];
            int x1 = query[1];
            int y2 = query[2];
            int x2 = query[3];
            answer.add(rotate(y1-1, x1-1, y2-1, x2-1));
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
    
    public int rotate(int y1, int x1, int y2, int x2) {
        List<Integer> usedNumbers = new ArrayList<>(numberMap[y1][x1]);
        int temp, temp2;
        temp2 = numberMap[y1][x1];
        for (int x = x1+1; x <= x2; x++) {
            temp = numberMap[y1][x];
            numberMap[y1][x] = temp2;
            usedNumbers.add(temp2);
            temp2 = temp;
        }
        for (int y = y1+1; y <= y2; y++) {
            temp = numberMap[y][x2];
            numberMap[y][x2] = temp2;
            usedNumbers.add(temp2);
            temp2 = temp;
        }
        for (int x = x2-1; x >= x1; x--) {
            temp = numberMap[y2][x];
            numberMap[y2][x] = temp2;
            usedNumbers.add(temp2);
            temp2 = temp;
        }
        for (int y = y2-1; y >= y1; y--) {
            temp = numberMap[y][x1];
            numberMap[y][x1] = temp2;
            usedNumbers.add(temp2);
            temp2 = temp;
        }
        return Collections.min(usedNumbers);
    }
}