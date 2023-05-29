/*
 * @lc app=leetcode id=1603 lang=c
 *
 * [1603] Design Parking System
 */

// @lc code=start
typedef struct
{
    int capacities[3];
} ParkingSystem;

ParkingSystem *parkingSystemCreate(int big, int medium, int small)
{
    ParkingSystem *obj = malloc(sizeof(ParkingSystem));
    obj->capacities[0] = big;
    obj->capacities[1] = medium;
    obj->capacities[2] = small;
    return obj;
}

bool parkingSystemAddCar(ParkingSystem *obj, int carType)
{
    if (obj->capacities[carType - 1] <= 0)
        return false;
    --obj->capacities[carType - 1];
    return true;
}

void parkingSystemFree(ParkingSystem *obj)
{
    free(obj);
}
/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);

 * parkingSystemFree(obj);
*/
// @lc code=end
