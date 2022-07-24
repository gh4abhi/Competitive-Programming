// Problem Link - https://leetcode.com/contest/weekly-contest-303/problems/design-a-food-rating-system/

#define ll int

class FoodRatings {
public:
    map<string,string> food;
    map<string,ll> rate;
    map<string,map<ll,ll>> cuis;
    map<string,map<ll,map<string,ll>>> fin;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(ll i=0;i<foods.size();i++)
        {
            food[foods[i]] = cuisines[i];
            rate[foods[i]] = ratings[i];
            cuis[cuisines[i]][ratings[i]]++;
            fin[cuisines[i]][ratings[i]][foods[i]]++;
        }
    }
    
    void changeRating(string foo, int newRating) {
        
        cuis[food[foo]][rate[foo]]--;
        if(cuis[food[foo]][rate[foo]]==0)
            cuis[food[foo]].erase(rate[foo]);
        fin[food[foo]][rate[foo]].erase(foo);
        if(fin[food[foo]][rate[foo]].size()==0)
            fin[food[foo]].erase(rate[foo]);
        fin[food[foo]][newRating][foo]++;
        cuis[food[foo]][newRating]++;
        rate[foo] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = fin[cuisine].end();
        it--;
        ll val = it->first;
        auto i = fin[cuisine][val].begin();
        return i->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */