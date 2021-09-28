// OJ: https://leetcode.com/problems/max-points-on-a-line/
// Author: github.com/ankuralld5999

class Solution {
private:
    int GCD(int a, int b) {
        if(b==0) 
            return a;
        else 
            return GCD(b, a%b);
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()<2) return points.size();
        
        int result=0;
        
        for(int i=0; i<points.size(); i++) {
            
            map<pair<int, int>, int> lines;
            int localmax=0, overlap=0, vertical=0;
            
            for(int j=i+1; j<points.size(); j++) {
                
                if(points[j][0]==points[i][0] && 
                   points[j][1]==points[i][1]) {
                    
                    overlap++;
                    continue;
                }
                else if(points[j][0]==points[i][0]) 
                    vertical++;
                else {
                    int a = points[j][0]-points[i][0];
                    int b = points[j][1]-points[i][1];
                    int gcd = GCD(a, b);
                    
                    a /= gcd;
                    b /= gcd;
                    
                    lines[make_pair(a, b)]++;
                    localmax = max(lines[make_pair(a, b)], localmax);
                }
                localmax = max(vertical, localmax);
            }
            
            result = max(result, localmax+overlap+1);
        }
        return result;
    }
};
