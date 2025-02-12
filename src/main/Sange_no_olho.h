#include "VL53.h"

class Sangue_no_olho
{
private:
  VL53_sensors VLs;

  int *distances;

public:
  int vls[3];

  void init_vls(TwoWire &wire);
  void up_date_dist();
};

void Sangue_no_olho::init_vls(TwoWire &wire)
{
  VLs.sensorsInit(wire);
}

void Sangue_no_olho::up_date_dist()
{
  distances = VLs.distanceRead();
}