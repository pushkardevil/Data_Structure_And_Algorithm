class Compare{
public:
    bool operator()(const pair<int,int> &a , const pair<int,int> &b){
        if(a.first==b.first){
            return a.second > b.second;
        }
        
        return a.first<b.first;
    }
};
