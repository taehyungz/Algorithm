import itertools
def solution(expression):
    answer = 0
    nums = expression.replace('-',' ').replace('+', ' ').replace('*',' ').split()
    ops = [i for i in expression if not i.isdigit()]
    set_ops = set(ops)
    for op_rank in itertools.permutations(set_ops,len(set_ops)):
        _nums = nums
        _ops = ops
        for high_op in op_rank:
            st_nums = [_nums[0]]
            st_op = []
            for i in range(len(_ops)):
                if high_op == _ops[i]:
                    n1 = st_nums.pop()
                    res = eval(str(n1)+high_op+str(_nums[i+1]))
                    st_nums.append(res)
                else:
                    st_nums.append(_nums[i+1])
                    st_op.append(_ops[i])
            _nums = st_nums
            _ops = st_op
        answer = max(answer, abs(st_nums[0]))
    
    return answer