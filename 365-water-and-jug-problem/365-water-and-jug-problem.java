class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z < 0 || z > x + y) {
            return false;
        }

        Set<Integer> visited = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        int[] options = new int[] {x, y, -x, -y};
        while (!queue.isEmpty()) {
            int s = queue.size();
            for (int i = 0; i < s; i++) {
                int cur = queue.poll();
                if (cur == z) {
                    return true;
                }
                for (int o : options) {
                    int next = cur + o;
                    if (next < 0 || next > x + y) {
                        continue;
                    }
                    if (!visited.contains(next)) {
                        if (next == z) {
                            return true;
                        }
                        queue.add(next);
                        visited.add(next);
                    }
                }
            }
        }
        return false;
    }
}