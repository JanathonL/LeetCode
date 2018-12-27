class MinStack {

    /** initialize your data structure here. */
    private ArrayList<Integer> list;
    private int num;
    
    public MinStack() {
        list = new ArrayList<>();
        num = 0;
    }
    
    public void push(int x) {
        list.add(x);
        num++;
    }
    
    public void pop() {
        num--;
    }
    
    public int top() {
        return list.get(num-1).intValue();
    }
    
    public int getMin() {
        int min = list.get(0).intValue();
        for(int i = 0; i < num; i++){
            if(list.get(i).intValue() < min){
                min = list.get(i).intValue();
            }
        }
        return min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */