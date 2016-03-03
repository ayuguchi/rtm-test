// -*- C++ -*-
/*!
 * @file  test_PosIn.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "test_PosIn.h"

#include <iostream>

// Module specification
// <rtc-template block="module_spec">
static const char* test_posin_spec[] =
  {
    "implementation_id", "test_PosIn",
    "type_name",         "test_PosIn",
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
test_PosIn::test_PosIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_PostionOutOut("PostionOut", m_PostionOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
test_PosIn::~test_PosIn()
{
}



RTC::ReturnCode_t test_PosIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("PostionOut", m_PostionOutOut);
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
RTC::ReturnCode_t test_PosIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t test_PosIn::onActivated(RTC::UniqueId ec_id)
{
  m_PostionOut.data.length(6);

  std::cout << "onActivated" << std::endl; 

  return RTC::RTC_OK;
}


RTC::ReturnCode_t test_PosIn::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << "onDeactivated" << std::endl; 

  return RTC::RTC_OK;
}


RTC::ReturnCode_t test_PosIn::onExecute(RTC::UniqueId ec_id)
{ 
  std::cout << "Input Target Postion in meter" << std::endl;
  std::cout << "X_Input= ";
  std::cin >> m_PostionOut.data[0];
  std::cout << "Y_Input= ";
  std::cin >> m_PostionOut.data[1];
  std::cout << "Z_Input= ";
  std::cin >> m_PostionOut.data[2];

  m_PostionOutOut.write();

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t test_PosIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t test_PosIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void test_PosInInit(RTC::Manager* manager)
  {
    coil::Properties profile(test_posin_spec);
    manager->registerFactory(profile,
                             RTC::Create<test_PosIn>,
                             RTC::Delete<test_PosIn>);
  }
  
};


