// -*- C++ -*-
/*!
 * @file  Package_consolidation.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Package_consolidation.h"

// Module specification
// <rtc-template block="module_spec">
static const char* package_consolidation_spec[] =
  {
    "implementation_id", "Package_consolidation",
    "type_name",         "Package_consolidation",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Manual", "0",
    "conf.default.debug", "0",

    // Widget
    "conf.__widget__.Manual", "radio",
    "conf.__widget__.debug", "radio",
    // Constraints
    "conf.__constraints__.Manual", "(0,1)",
    "conf.__constraints__.debug", "(0,1)",

    "conf.__type__.Manual", "int",
    "conf.__type__.debug", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Package_consolidation::Package_consolidation(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_Weight_DataIn("Weight_Data", m_Weight_Data),
    m_Size_DataIn("Size_Data", m_Size_Data),
    m_Baggage_DataOut("Baggage_Data", m_Baggage_Data)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Package_consolidation::~Package_consolidation()
{
}



RTC::ReturnCode_t Package_consolidation::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Weight_Data", m_Weight_DataIn);
  addInPort("Size_Data", m_Size_DataIn);
  
  // Set OutPort buffer
  addOutPort("Baggage_Data", m_Baggage_DataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Manual", m_Manual, "0");
  bindParameter("debug", m_debug, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Package_consolidation::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Package_consolidation::onActivated(RTC::UniqueId ec_id)
{
  Weight=0;
  Size=0;
  m_Baggage_Data.data.length(5);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Package_consolidation::onDeactivated(RTC::UniqueId ec_id)
{
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Package_consolidation::onExecute(RTC::UniqueId ec_id)
{
  
  if(m_Manual==0)
    {
      if( m_Weight_DataIn.isNew())
	{
	  m_Weight_DataIn.read();
	  Weight=1;
	}
      if(m_Size_DataIn.isNew())
	{
	  m_Size_DataIn.read();
	  Size=1;
	}
      if(Size==1&&Weight==1)
	{
	  if(m_Size_Data.data[0]==1&&m_Weight_Data.data>10)
	    {
	      m_Baggage_Data.data[0]=m_Size_Data.data[0];
	    }
	  else if(m_Weight_Data.data>10)
	    {
	      m_Baggage_Data.data[0]=-2;
	    }
	  else
	    {
	      m_Baggage_Data.data[0]=-1;
	    }
	  
	  m_Baggage_Data.data[1]=m_Size_Data.data[1];
	  m_Baggage_Data.data[2]=m_Size_Data.data[2];
	  m_Baggage_Data.data[3]=m_Size_Data.data[3];
	  m_Baggage_Data.data[4]=m_Weight_Data.data;
	  m_Baggage_DataOut.write();
	  Size=0;
	  Weight=0;
	}
    }
  else//手動の場合
    {
      std::cout<<"Manual Input"<<std::endl;
      std::cout<<"Object:Yes/No=1/0"<<std::endl;
      std::cin>>m_Baggage_Data.data[0];
      std::cout<<"Length"<<std::endl;
      std::cin>>m_Baggage_Data.data[1];
      std::cout<<"Width"<<std::endl;
      std::cin>>m_Baggage_Data.data[2];
      std::cout<<"Hight"<<std::endl;
      std::cin>>m_Baggage_Data.data[3];
      std::cout<<"Weight"<<std::endl;
      std::cin>>m_Baggage_Data.data[4];
      m_Baggage_DataOut.write();
    }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Package_consolidation::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Package_consolidation::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void Package_consolidationInit(RTC::Manager* manager)
  {
    coil::Properties profile(package_consolidation_spec);
    manager->registerFactory(profile,
                             RTC::Create<Package_consolidation>,
                             RTC::Delete<Package_consolidation>);
  }
  
};


