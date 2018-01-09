// -*- C++ -*-
/*!
 * @file  DeliveryDatabaseRTC.cpp
 * @brief DeliveryDatabaseRTC
 * @date $Date$
 *
 * $Id$
 */

#include "DeliveryDatabaseRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* deliverydatabasertc_spec[] =
  {
    "implementation_id", "DeliveryDatabaseRTC",
    "type_name",         "DeliveryDatabaseRTC",
    "description",       "DeliveryDatabaseRTC",
    "version",           "1.0.0",
    "vendor",            "VenderName",
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
DeliveryDatabaseRTC::DeliveryDatabaseRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_DeliveryDatabaseInterfacePort("DeliveryDatabaseInterface")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DeliveryDatabaseRTC::~DeliveryDatabaseRTC()
{
}



RTC::ReturnCode_t DeliveryDatabaseRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_DeliveryDatabaseInterfacePort.registerProvider("DeliveryDatabaseInterface", "DeriveryDatabase::DeriveryDatabaseInterface", m_DeliveryDatabaseInterface);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_DeliveryDatabaseInterfacePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t DeliveryDatabaseRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DeliveryDatabaseRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t DeliveryDatabaseRTC::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DeliveryDatabaseRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void DeliveryDatabaseRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(deliverydatabasertc_spec);
    manager->registerFactory(profile,
                             RTC::Create<DeliveryDatabaseRTC>,
                             RTC::Delete<DeliveryDatabaseRTC>);
  }
  
};


