class MyHashMap {

    HashMap<Integer,Integer> map;

    public MyHashMap() {
        map = new HashMap<>();
    }
    
    public void put(int key, int value) {
        map.put(key,value);
    }
    
    public int get(int key) {
        if(map.get(key) == null) return -1;
        return map.get(key);
    }
    
    public void remove(int key) {
        map.remove(key);
    }
}