class Robot {
private:
    int w, h, perimeter;
    int pos;
    bool hasMoved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
       
        perimeter = 2 * (w - 1) + 2 * (h - 1);
        pos = 0;
        hasMoved = false;
    }
    
    void step(int num) {
        hasMoved = true;
    
        pos = (pos + num) % perimeter;
    }
    
    vector<int> getPos() {
        // Bottom edge
        if (pos <= w - 1) {
            return {pos, 0};
        } 
        // Right edge
        else if (pos <= (w - 1) + (h - 1)) {
            return {w - 1, pos - (w - 1)};
        } 
        // Top edge
        else if (pos <= 2 * w + h - 3) {
            return {w - 1 - (pos - (w - 1) - (h - 1)), h - 1};
        } 
        // Left edge
        else {
            return {0, h - 1 - (pos - (2 * w + h - 3))};
        }
    }
    
    string getDir() {
        
        if (pos == 0) {
            return hasMoved ? "South" : "East";
        } 
        // Bottom edge
        else if (pos <= w - 1) {
            return "East";
        } 
        // Right edge
        else if (pos <= (w - 1) + (h - 1)) {
            return "North";
        } 
        // Top edge
        else if (pos <= 2 * w + h - 3) {
            return "West";
        } 
        // Left edge
        else {
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */