import heapq

def dijkstra(graph, start):
    V = len(graph)
    dist = [float('inf')] * V
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        current_dist, u = heapq.heappop(pq)

        if current_dist > dist[u]:
            continue

        for v, weight in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))

    return dist

graph = {
    0: [(1, 10), (3, 5)],
    1: [(2, 1)],
    2: [(4, 4)],
    3: [(1, 3), (2, 9), (4, 2)],
    4: [(2, 6)]
}
start = 0
distances = dijkstra(graph, start)
print(f"Shortest distances from vertex {start} to all other vertices: {distances}")
