from collections import defaultdict


def solution(id_list, report, k):
    answer = [0 for i in range(len(id_list))]
    name_idx_map = dict((id_list[i], i) for i in range(len(id_list)))
    reportee_reported_by_map = defaultdict(list)
    reported_count_map = defaultdict(int)
    report = list(set(report))

    for rep in report:
        reporter, reportee = rep.split()
        reportee_reported_by_map[reportee].append(reporter)
        reported_count_map[reportee] += 1
    for reportee, count in reported_count_map.items():
        if count >= k:
            reporter_list = reportee_reported_by_map[reportee]
            for reporter in reporter_list:
                answer[name_idx_map[reporter]] += 1
    return answer