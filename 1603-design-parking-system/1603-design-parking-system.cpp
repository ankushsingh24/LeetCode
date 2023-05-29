class ParkingSystem {
public:
    int one, two, three;
    
    ParkingSystem(int big, int medium, int small) 
    {
        one = big;
        two = medium;
        three = small;
    }
    
    bool addCar(int carType) 
    {
        if(carType == 1)
        {
            if(one > 0)
            {
                one--;
                return true;
            }
            else
                return false;
        }
        
        else if(carType == 2)
        {
            if(two > 0)
            {
                two--;
                return true;
            }
            else
                return false;
        }
        
        else if(carType == 3)
        {
            if(three > 0)
            {
                three--;
                return true;
            }
            else
                return false;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */