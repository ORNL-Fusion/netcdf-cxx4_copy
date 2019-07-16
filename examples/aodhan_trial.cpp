//Trial of making my own netcdf code to become more comfortable
#include <iostream>
#include <string>
#include <netcdf>
using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

static const int NLAT = 6;
static const int NLON = 12;

#define BZIP2_ID 307
#define BZIP2_LEVEL 9
unsigned int level = BZIP2_LEVEL;

float lats[NLAT];
float lons[NLON];

float pres[NLAT][NLON];
float temp[NLAT][NLON];

int main(){
  std::cout<<"============================\n this is the example output \n ";

  NcFile dataFile("simple_xy_nc4.nc", NcFile::read);
  string newname_is = "new_file";
  NcVar grid_data;
  grid_data = dataFile.getVar("data");

  cout<<"there are "<<dataFile.getVarCount()<<" variables"<<endl;
  cout<<"there are "<<dataFile.getAttCount()<<" attributes"<<endl;
  cout<<"there are "<<dataFile.getDimCount()<<" dimensions"<<endl;
  cout<<"there are "<<dataFile.getGroupCount()<<" groups"<<endl;
  cout<<"there are "<<dataFile.getTypeCount()<<" types"<<endl;


  NcFile data("sfc_pres_temp.nc", NcFile::write);


  data.open("sfc_pres_temp.nc", NcFile::write);

  //using redef() wrapper
  data.redef();

  //using set_Fill() wrapper

  //using filter functionality
  NcVar latitude = data.getVar("latitude");
  NcVar longitude = data.getVar("longitude");
  NcVar pressure = data.getVar("pressure");
  NcVar temperature = data.getVar("temperature");


  latitude.getVar(lats);
  longitude.getVar(lons);
  pressure.getVar(pres);


  return 0;
}
