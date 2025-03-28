class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if(num==0) v={1};
        else v.push_back(v.back()*num);
    }
    
    int getProduct(int k) {
        int n=v.size();
        if(k>=n) return 0;
        return v.back()/v[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */