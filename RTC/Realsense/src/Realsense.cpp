// -*- C++ -*- /*!
/* @file  Realsense.cpp
 * @brief Realsense Comp for linux
 * @date $Date$
 *
 * $Id$
 */

#include "Realsense.h"

// Module specification
// <rtc-template block="module_spec">
static const char* realsense_spec[] =
  {
    "implementation_id", "Realsense",
    "type_name",         "Realsense",
    "description",       "Realsense Comp for linux",
    "version",           "1.1.2",
    "vendor",            "Yuki Takamido",
    "category",          "Cupture",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.output_color_format", "RGB",
    "conf.default.output_color_format_depth", "RGB",

    // Widget
    "conf.__widget__.output_color_format", "text",
    "conf.__widget__.output_color_format_depth", "text",
    // Constraints

    "conf.__type__.output_color_format", "string",
    "conf.__type__.output_color_format_depth", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
Realsense::Realsense(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_CameraDepthOut("CameraDepth", m_CameraDepth),
    m_CameraImageOut("CameraImage", m_CameraImage),
    m_DepthScaleOut("DepthScale", m_DepthScale)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Realsense::~Realsense()
{
}



RTC::ReturnCode_t Realsense::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("CameraDepth", m_CameraDepthOut);
  addOutPort("CameraImage", m_CameraImageOut);
  addOutPort("DepthScale", m_DepthScaleOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("output_color_format", m_output_color_format, "RGB");
  bindParameter("output_color_format_depth", m_output_color_format_depth, "RGB");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Realsense::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t Realsense::onActivated(RTC::UniqueId ec_id)
{


  dev=ctx.get_device(0);
  dev->enable_stream(rs::stream::color, 640, 480, rs::format::bgr8, 30);
  dev->enable_stream(rs::stream::depth,640,480,rs::format::z16,30);
  
  dev->start();
  
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Realsense::onDeactivated(RTC::UniqueId ec_id)
{
  dev->stop();

  return RTC::RTC_OK;
}


RTC::ReturnCode_t Realsense::onExecute(RTC::UniqueId ec_id)
{
  dev->wait_for_frames();
  cv::Mat src_image(cv::Size(640, 480),CV_8UC3, (uchar*)dev->get_frame_data(rs::stream::color));
  cv::Mat src_depth(cv::Size(640, 480),CV_16UC1, (uchar*)dev->get_frame_data(rs::stream::depth));
  
  intrin_depth=dev->get_stream_intrinsics(rs::stream::depth);
  intrin_color=dev->get_stream_intrinsics(rs::stream::color);
  
  //***********************************************************************************
  
  //***********************************************************************************
  
  //Following part is the template for common camera interface
  
  //Don't change following part
  
  //***********************************************************************************
  
  //***********************************************************************************
  
  
  
  //Set timestamp
  
  setTimestamp(m_CameraImage);
  
  m_CameraImage.data.captured_time = m_CameraImage.tm;
  
  m_CameraDepth.data.captured_time=m_CameraImage.tm;
  m_CameraDepth.tm = m_CameraImage.tm;
  
  //Color conversion process
  
  cv::Mat proc_image;
  cv::Mat proc_depth;
  
  if(nchannels > src_image.channels())
    
    {
      
      if( m_output_color_format == "RGB" || m_output_color_format == "JPEG" || m_output_color_format == "PNG")
	cv::cvtColor(src_image, proc_image, CV_GRAY2RGB);
      
      nchannels = 3;
      
    }
  
  
  else if( nchannels < src_image.channels() )
    
    {
      
      if( m_output_color_format == "GRAY" )
	
	{
	  
	  cv::cvtColor(src_image, proc_image, CV_BGR2GRAY);
	  
	  nchannels = 1;
	  
        }
      
    }
  
  else
    
    {
      
      if( m_output_color_format == "RGB" || m_output_color_format == "JPEG" || m_output_color_format == "PNG")
	{
	
	cv::cvtColor(src_image, proc_image, CV_BGR2RGB);
	}
      else
	
	proc_image = src_image;
      
    }
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  //Depth画像
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  /*
  if(nchannels_depth > src_depth.channels())
    
    {
      
      if( m_output_color_format_depth == "RGB" || m_output_color_format_depth == "JPEG" || m_output_color_format_depth == "PNG")
	
	cv::cvtColor(src_depth, proc_depth, CV_GRAY2RGB);
      
      nchannels_depth = 3;
      
    }
  
  
  else if( nchannels_depth < src_depth.channels() )
    
    {
      
      if( m_output_color_format_depth == "GRAY" )
	
	{
		
	  cv::cvtColor(src_depth, proc_depth, CV_BGR2GRAY);
	  
	  nchannels_depth = 1;
	  
        }
      
    }
  
  else
    
    {
      
      if( m_output_color_format_depth == "RGB" || m_output_color_format_depth == "JPEG" || m_output_color_format_depth == "PNG")
	{
	
	cv::cvtColor(src_depth, proc_depth, CV_GRAY2RGB);
	}
      else
	
	proc_depth = src_depth;
      
    }
  */
  
  
  //Set camera parameter to output structure data
	
  m_CameraImage.data.intrinsic.matrix_element[0] = intrin_color.fx;
  m_CameraImage.data.intrinsic.matrix_element[1] = intrin_color.ppx;
  m_CameraImage.data.intrinsic.matrix_element[2] = intrin_color.fy;
  m_CameraImage.data.intrinsic.matrix_element[3] = intrin_color.ppy;
  m_CameraImage.data.intrinsic.matrix_element[4] = 1;
  
  m_CameraDepth.data.intrinsic.matrix_element[0] = intrin_depth.fx;
  m_CameraDepth.data.intrinsic.matrix_element[1] = intrin_depth.ppx;
  m_CameraDepth.data.intrinsic.matrix_element[2] = intrin_depth.fy;
  m_CameraDepth.data.intrinsic.matrix_element[3] = intrin_depth.ppy;
  m_CameraDepth.data.intrinsic.matrix_element[4] = 1;
  
  /*
  //Copy undistortion matrix
  
  m_CameraImage.data.intrinsic.distortion_coefficient.length(cam_param.distCoeffs.rows);
  
  cv::Mat distortion_temp;
  
  if(coil::toBool(m_undistortion_flag, "true", "false"))
  
  {
  
  if(isFileLoad)
  
  {
  
  distortion_temp = proc_image.clone();
  
  cv::undistort(distortion_temp, proc_image, cam_param.cameraMatrix, cam_param.distCoeffs, cam_param.cameraMatrix);
  
  
  
  }
  
  //Copy distortion coefficient to output parameter
  
  for(int j(0); j < 5; ++j)
  
  m_CameraImage.data.intrinsic.distortion_coefficient[j] = 0.0; 
  
  }
  */
  
  
  
  //Copy distortion coefficient to output parameter
  for(int j(0); j < 5; ++j)
    {
      // m_CameraImage.data.intrinsic.distortion_coefficient[j] = 0.0;//(double)intrin_color.coeffs[j];
      //m_CameraDepth.data.intrinsic.distortion_coefficient[j] = 0.0;//(double)intrin_depth.coeffs[j];
      
    }
  
  
  
  
  //Copy image parameter to output data based on TimedCameraImage structure
  
  m_CameraImage.data.image.width = intrin_color.width;
  
  m_CameraImage.data.image.height = intrin_color.height;
  
  
  m_CameraDepth.data.image.width = intrin_depth.width;
  
  m_CameraDepth.data.image.height = intrin_depth.height;
  
  
  
  //Transmission image data creation based on selected image compression mode
  
  if( m_output_color_format == "RGB")
    
    {
      
      m_CameraImage.data.image.format = Img::CF_RGB;
      
      m_CameraImage.data.image.raw_data.length( intrin_color.height * intrin_color.width * nchannels);
      
      for( int i(0); i<intrin_color.height ; ++i )
	
	memcpy(&m_CameraImage.data.image.raw_data[ i * intrin_color.width * nchannels], &proc_image.data[ i *proc_image.step  ], intrin_color.width * nchannels);
      
    }
  
  else if(m_output_color_format == "JPEG")
    
    {
      
      m_CameraImage.data.image.format = Img::CF_JPEG;
      
      //Jpeg encoding using OpenCV image compression function
      
      std::vector<int> compression_param = std::vector<int>(2); 
      
      compression_param[0] = CV_IMWRITE_JPEG_QUALITY;
      
      compression_param[1] = 75;
      
      //Encode raw image data to jpeg data
      
      std::vector<uchar> compressed_image;
      
      cv::imencode(".jpg", proc_image, compressed_image, compression_param);
      
      //Copy encoded jpeg data to Outport Buffer
      
      m_CameraImage.data.image.raw_data.length(compressed_image.size());
      
      memcpy(&m_CameraImage.data.image.raw_data[0], &compressed_image[0], sizeof(unsigned char) * compressed_image.size());
      
    }
  
  else if(m_output_color_format == "PNG")
    
    {
      
      m_CameraImage.data.image.format = Img::CF_PNG;
      
      //Jpeg encoding using OpenCV image compression function
      
      std::vector<int> compression_param = std::vector<int>(2); 
      
      compression_param[0] = CV_IMWRITE_PNG_COMPRESSION;
      
      compression_param[1] = (int)((double)75/10.0);
      
      if(compression_param[1] == 10)
	
	compression_param[1] = 9;
      
      std::cout<<"PNG compression ratio: "<<compression_param[1] << "\r";
      
      
      
      
      
      //Encode raw image data to jpeg data
      
      std::vector<uchar> compressed_image;
      
      cv::imencode(".png", proc_image, compressed_image, compression_param);
      
      //Copy encoded jpeg data to Outport Buffer
      
      m_CameraImage.data.image.raw_data.length(compressed_image.size());
      
      memcpy(&m_CameraImage.data.image.raw_data[0], &compressed_image[0], sizeof(unsigned char) * compressed_image.size());
      
    }
  
  else
    
    {
      
      m_CameraImage.data.image.format = Img::CF_GRAY;
      
      
      
      std::cout<<"Selected image compression mode is not defined. Please confirm correct compression mode!"<<std::endl;
      
      m_CameraImage.data.image.raw_data.length( intrin_color.width * intrin_color.height * nchannels);
      
      for( int i(0); i< intrin_color.height; ++i )
	
	memcpy(&m_CameraImage.data.image.raw_data[ i * intrin_color.width * nchannels], &proc_image.data[ i * proc_image.step ], intrin_color.width * nchannels);			
      
    }
  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////for Depth  ////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Transmission image data creation based on selected image compression mode
  /*
  if( m_output_color_format_depth == "RGB")
    
    {
      
      m_CameraDepth.data.image.format = Img::CF_RGB;
      
      m_CameraDepth.data.image.raw_data.length( intrin_depth.width * intrin_depth.height * nchannels_depth*2.0);
      
      for( int i(0); i< intrin_depth.height; ++i )
	
	memcpy(&m_CameraDepth.data.image.raw_data[ i * intrin_depth.width * nchannels_depth*2], &proc_depth.data[ i * proc_depth.step ], intrin_depth.width * nchannels_depth);
      
    }
  
  else if(m_output_color_format_depth == "JPEG")
    
    {
      
      m_CameraDepth.data.image.format = Img::CF_JPEG;
      
      //Jpeg encoding using OpenCV image compression function
      
      std::vector<int> compression_param = std::vector<int>(2); 
      
      compression_param[0] = CV_IMWRITE_JPEG_QUALITY;
      
      compression_param[1] = 75;
      
      //Encode raw image data to jpeg data
      
      std::vector<uchar> compressed_image;
      
      cv::imencode(".jpg", proc_depth, compressed_image, compression_param);
      
      //Copy encoded jpeg data to Outport Buffer
      
      m_CameraDepth.data.image.raw_data.length(compressed_image.size());
      
      memcpy(&m_CameraDepth.data.image.raw_data[0], &compressed_image[0], sizeof(unsigned char) * compressed_image.size());
      
    }
  
  else if(m_output_color_format_depth == "PNG")
    
    {
      
      m_CameraDepth.data.image.format = Img::CF_PNG;
      
      //Jpeg encoding using OpenCV image compression function
      
      std::vector<int> compression_param = std::vector<int>(2); 
      
      compression_param[0] = CV_IMWRITE_PNG_COMPRESSION;
      
      compression_param[1] = (int)((double)75/10.0);
      
      if(compression_param[1] == 10)
	
	compression_param[1] = 9;
      
      std::cout<<"PNG compression ratio: "<<compression_param[1] << "\r";
      
      
      
      
      
      //Encode raw image data to jpeg data
      
      std::vector<uchar> compressed_image;
      
      cv::imencode(".png", proc_depth, compressed_image, compression_param);
      
      //Copy encoded jpeg data to Outport Buffer
      
      m_CameraDepth.data.image.raw_data.length(compressed_image.size());
      
      memcpy(&m_CameraDepth.data.image.raw_data[0], &compressed_image[0], sizeof(unsigned char) * compressed_image.size());
      
    }
  
  else
    
    {
      */
      m_CameraDepth.data.image.format = Img::CF_GRAY;
      
      
      
      //  std::cout<<"Selected image compression mode is not defined. Please confirm correct compression mode!"<<std::endl;
      
      m_CameraDepth.data.image.raw_data.length( intrin_depth.width * intrin_depth.height * nchannels_depth*2);
      
      for( int i(0); i< intrin_depth.height; ++i )
	
	memcpy(&m_CameraDepth.data.image.raw_data[ i * intrin_depth.width * nchannels_depth*2], &src_depth.data[ i * src_depth.step ], intrin_depth.width * nchannels_depth*2);			
      
      //  }
  
  //Output image data via OutPort
  
  m_CameraImageOut.write();
  m_CameraDepthOut.write();
  
  //***********************************************************************************
  
  //End of the template part
  
  //***********************************************************************************

  m_DepthScale.data=(double)dev->get_depth_scale();
  m_DepthScaleOut.write();


 // cv::imshow("TestWindow",src_image);
  cv::waitKey(1);
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Realsense::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t Realsense::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void RealsenseInit(RTC::Manager* manager)
  {
    coil::Properties profile(realsense_spec);
    manager->registerFactory(profile,
                             RTC::Create<Realsense>,
                             RTC::Delete<Realsense>);
  }
  
};


