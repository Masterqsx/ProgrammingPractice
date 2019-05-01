class Solution:
    directs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    def dfs(self, visited, blocked, i: int, j: int, count: List[int]):
        visited.add(i * 1000000 + j)
        for d in self.directs:
            iN = i + d[0]
            jN = j + d[1]
            index = iN * 1000000 + jN
            if iN >= 0 and iN < 1000000 and jN >= 0 and jN < 1000000 and index not in blocked and index not in visited and count[0] < 20000:
                count[0] = count[0] + 1
                self.dfs(visited, blocked, iN, jN, count)
        
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
        block = set();     
        for i in range(len(blocked)):
            x = blocked[i][0]
            y = blocked[i][1]
            block.add(x * 1000000 + y)
        countS = [0]
        countT = [0]
        visited = set();
        self.dfs(visited, block, source[0], source[1], countS)
        visited = set();
        self.dfs(visited, block, target[0], target[1], countT)
        if countS[0] == 20000 and countT[0] == 20000:
            return True
        else:
            return False
