class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
   
        int closestX = std::clamp(xCenter, x1, x2);
        int closestY = std::clamp(yCenter, y1, y2);
        
     
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;
        
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};