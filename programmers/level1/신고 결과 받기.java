import java.util.*;
import java.util.stream.Collectors;

class Solution {
    Map<String, Integer> reporter_idx_map = new HashMap<>();
    Map<String, Integer> reported_count_map = new HashMap<>();
    Map<String, List<String>> reportee_reported_by_map = new HashMap<>();

    public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        List<String> reportList = Arrays.stream(report)
            .distinct()
            .collect(Collectors.toList());

        for (int i = 0; i < id_list.length; i++) {
            reporter_idx_map.put(id_list[i], i);
        }
        for (String rep: reportList) {
            String[] rep_info = rep.split(" ");
            reported_count_map.put(rep_info[1], reported_count_map.getOrDefault(rep_info[1], 0) + 1);
            addReporteeReportedBy(rep_info[0], rep_info[1]);
        }
        for (Map.Entry<String, Integer> entry: reported_count_map.entrySet()) {
            if (entry.getValue() >= k) {
                List<String> reporters = reportee_reported_by_map.getOrDefault(entry.getKey(), List.of());
                for (String reporter: reporters) {
                        answer[reporter_idx_map.get(reporter)] += 1;
                }
            }
        }
        return answer;
    }

    public void addReporteeReportedBy(String reporter, String reportee) {
        if (reportee_reported_by_map.containsKey(reportee)) {
            List<String> reporters = reportee_reported_by_map.get(reportee);
            reporters.add(reporter);
        } else {
            reportee_reported_by_map.put(reportee, new ArrayList(List.of(reporter)));
        }
    }
}