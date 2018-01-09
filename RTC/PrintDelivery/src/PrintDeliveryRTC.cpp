// -*- C++ -*-
/*!
 * @file  PrintDeliveryRTC.cpp
 * @brief PrintDeliveryRTC
 * @date $Date$
 *
 * $Id$
 */

#include "PrintDeliveryRTC.h"

// Module specification
// <rtc-template block="module_spec">
static const char* printdeliveryrtc_spec[] =
  {
    "implementation_id", "PrintDeliveryRTC",
    "type_name",         "PrintDeliveryRTC",
    "description",       "PrintDeliveryRTC",
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
PrintDeliveryRTC::PrintDeliveryRTC(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_PrintDeliveryInterfacePort("PrintDeliveryInterface")

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
PrintDeliveryRTC::~PrintDeliveryRTC()
{
}



RTC::ReturnCode_t PrintDeliveryRTC::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  m_PrintDeliveryInterfacePort.registerProvider("PrintDeliveryInterface", "PrintDelivery::PrintDeriveryInterface", m_PrintDeliveryInterface);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_PrintDeliveryInterfacePort);
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PrintDeliveryRTC::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t PrintDeliveryRTC::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t PrintDeliveryRTC::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t PrintDeliveryRTC::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t PrintDeliveryRTC::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t PrintDeliveryRTC::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void PrintDeliveryRTCInit(RTC::Manager* manager)
  {
    coil::Properties profile(printdeliveryrtc_spec);
    manager->registerFactory(profile,
                             RTC::Create<PrintDeliveryRTC>,
                             RTC::Delete<PrintDeliveryRTC>);
  }
  
};


