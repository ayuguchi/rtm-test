// -*- C++ -*-
/*!
 * @file  test_OrienIn.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "test_OrienIn.h"

 #include <iostream>

// Module specification
// <rtc-template block="module_spec">
static const char* test_orienin_spec[] =
  {
    "implementation_id", "test_OrienIn",
    "type_name",         "test_OrienIn",
    "description",       "ModuleDescription",
    "version",           "1.1.0",
    "vendor",            "Akishige YUGUCHI",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
test_OrienIn::test_OrienIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_OrientationOutOut("OrientationOut", m_OrientationOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
test_OrienIn::~test_OrienIn()
{
}



RTC::ReturnCode_t test_OrienIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("OrientationOut", m_OrientationOutOut);
  std::cout << "onInitialize" << std::endl;
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t test_OrienIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t test_OrienIn::onActivated(RTC::UniqueId ec_id)
{
  std::cout << "onActivated" << std::endl; 
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t test_OrienIn::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << "onDeactivated" << std::endl; 
  return RTC::RTC_OK;
}


RTC::ReturnCode_t test_OrienIn::onExecute(RTC::UniqueId ec_id)
{
  std::cout << "Input Orientation in degree" << std::endl;
  std::cout << "Pitch_Input= ";
  std::cin >> m_OrientationOut.data.p ;
  std::cout << "Yaw_Input= ";
  std::cin >> m_OrientationOut.data.y ;
  std::cout << "Roll_Input= ";
  std::cin >> m_OrientationOut.data.r ;

  m_OrientationOutOut.write(); 

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t test_OrienIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_OrienIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void test_OrienInInit(RTC::Manager* manager)
  {
    coil::Properties profile(test_orienin_spec);
    manager->registerFactory(profile,
                             RTC::Create<test_OrienIn>,
                             RTC::Delete<test_OrienIn>);
  }
  
};


