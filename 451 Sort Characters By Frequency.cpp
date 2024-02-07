class Solution {
public:
    string frequencySort(string s) {
        //Make a vector to store the letter and its frequency
         typedef pair<char,int> P;

         vector<P> vec(123);

         for(char &ch:s){
             int freq=vec[ch].second;
             vec[ch]={ch,freq+1};
         }
         
         auto lambda= [&](P & p1,P &p2){
             return p1.second >p2.second;
         };

         sort(vec.begin(),vec.end(),lambda);

         string result ="";

         for(int i=0;i<123;i++){
             if(vec[i].second >0){
                 char ch=vec[i].first;
                 int freq=vec[i].second;
                 string temp= string(freq,ch);

                 result +=temp;
             }
         }
         return result;


    }
};
