import heapq

def prim(graph, start):
    V = len(graph)
    mst = []
    visited = [False] * V
    min_heap = [(0, start, -1)]
    
    while min_heap:
        weight, u, parent = heapq.heappop(min_heap)
        
        if visited[u]:
            continue
        
        visited[u] = True
        if parent != -1:
            mst.append((parent, u, weight))
        
        for v, w in graph[u]:
            if not visited[v]:
                heapq.heappush(min_heap, (w, v, u))
    
    return mst

graph = {
    0: [(1, 10), (3, 5)],
    1: [(0, 10), (2, 1), (3, 3)],
    2: [(1, 1), (3, 9), (4, 4)],
    3: [(0, 5), (1, 3), (2, 9), (4, 2)],
    4: [(2, 4), (3, 2)]
}
start = 0
mst = prim(graph, start)
print("Edges in the MST:")
for u, v, weight in mst:
    print(f"{u} -- {v} == {weight}")
