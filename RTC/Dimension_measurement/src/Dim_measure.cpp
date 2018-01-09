// -*- C++ -*-
/*!
 * @file  Dim_measure.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "Dim_measure.h"

// Module specification
// <rtc-template block="module_spec">
static const char* dim_measure_spec[] =
  {
    "implementation_id", "Dim_measure",
    "type_name",         "Dim_measure",
    "description",       "ModuleDescription",
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
Dim_measure::Dim_measure(RTC::Manager* manager)
  // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_Depth_ImageIn("Depth_Image", m_Depth_Image),
    m_Depth_ScaleIn("Depth_Scale", m_Depth_Scale),
    m_Top_CameraIn("Top_Camera", m_Top_Camera),
    m_Flont_CameraIn("Flont_Camera", m_Flont_Camera),
    m_SizeOut("Size", m_Size)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
Dim_measure::~Dim_measure()
{
}



RTC::ReturnCode_t Dim_measure::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("Depth_Image", m_Depth_ImageIn);
  addInPort("Depth_Scale", m_Depth_ScaleIn);
  addInPort("Top_Camera", m_Top_CameraIn);
  addInPort("Flont_Camera", m_Flont_CameraIn);
  
  // Set OutPort buffer
  addOutPort("Size", m_SizeOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
  RTC::ReturnCode_t Dim_measure::onFinalize()
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onStartup(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onShutdown(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/


RTC::ReturnCode_t Dim_measure::onActivated(RTC::UniqueId ec_id)
{
  Depth_F=false;
  Top_F=false;
  Flont_F=false;
  m_Size.data.length(4);
  
  int depth_count=0;
  while(depth_count!=100)
    {
      if(m_Depth_ImageIn.isNew())
	{
	  m_Depth_ImageIn.read();
	  depth_count++;
	}
    }
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Dim_measure::onDeactivated(RTC::UniqueId ec_id)
{
  //古いデータをすべて読み込む
  if(m_Depth_ImageIn.isNew())
    {
      while(!m_Depth_ImageIn.isEmpty())
	m_Depth_ImageIn.read();
    }
  if(m_Depth_ScaleIn.isNew())
    {
      while(!m_Depth_ScaleIn.isEmpty())
	m_Depth_ScaleIn.read();
    }
  if(m_Top_CameraIn.isNew())
    {
      while(!m_Top_CameraIn.isEmpty())
	m_Top_CameraIn.read();
    }
  if(m_Flont_CameraIn.isNew())
    {
      while(!m_Flont_CameraIn.isEmpty())
	m_Flont_CameraIn.read();
    }
  return RTC::RTC_OK;
}


RTC::ReturnCode_t Dim_measure::onExecute(RTC::UniqueId ec_id)
{
  if(m_Depth_ImageIn.isNew())
    {
      while(!m_Depth_ImageIn.isEmpty())
	m_Depth_ImageIn.read();

      Depth_Image.create(m_Depth_Image.data.image.height,m_Depth_Image.data.image.width,CV_16UC1);

      for(int i=0;i<m_Depth_Image.data.image.height;++i)
	{
	  memcpy(&Depth_Image.data[i*Depth_Image.step],
		 &m_Depth_Image.data.image.raw_data[i*m_Depth_Image.data.image.width*2],
		 sizeof(unsigned short)*m_Depth_Image.data.image.width);
	}
      if(m_Depth_ScaleIn.isNew())
	{
	  while(!m_Depth_ScaleIn.isEmpty())
	    m_Depth_ScaleIn.read();

	  Depth_Image.convertTo(Depth_Image,CV_64F);

	  Depth_Image=Depth_Image*m_Depth_Scale.data;
	      
	  if(!Depth_F)
	    {
	      std::cout<<"Get first depth image"<<std::endl;
	      Depth_Image.copyTo(Depth_Image_Def);
	      Depth_F=true;
	    }
	}
    }

  
  if(m_Top_CameraIn.isNew())
    {
      while(!m_Top_CameraIn.isEmpty())
	m_Top_CameraIn.read();
    		
      int width = m_Top_Camera.data.image.width;
      int height = m_Top_Camera.data.image.height;
      int channels = (m_Top_Camera.data.image.format == Img::CF_GRAY) ? 1 :
	(m_Top_Camera.data.image.format == Img::CF_RGB || m_Top_Camera.data.image.format == Img::CF_PNG || m_Top_Camera.data.image.format == Img::CF_JPEG) ? 3 :
	(m_Top_Camera.data.image.raw_data.length()/width/height);
      RTC_TRACE(("Capture image size %d x %d", width, height));
      RTC_TRACE(("Channels %d", channels));
		
      if(channels == 3)
	Top_Image.create(height, width, CV_8UC3);
      else
	Top_Image.create(height, width, CV_8UC1);		

      long data_length = m_Top_Camera.data.image.raw_data.length();
      //long image_size = width * height * channels;

      if( m_Top_Camera.data.image.format == Img::CF_RGB )
	{
	  for(int i=0; i<height; ++i)
	    memcpy(&Top_Image.data[i*Top_Image.step],&m_Top_Camera.data.image.raw_data[i*width*channels],sizeof(unsigned char)*width*channels);
	  if(channels == 3)
	    cv::cvtColor(Top_Image, Top_Image, CV_RGB2BGR);
	}
      else if( m_Top_Camera.data.image.format == Img::CF_JPEG || m_Top_Camera.data.image.format == Img::CF_PNG )
	{
	  std::vector<uchar> compressed_image = std::vector<uchar>(data_length);
	  memcpy(&compressed_image[0], &m_Top_Camera.data.image.raw_data[0], sizeof(unsigned char) * data_length);

	  //Decode received compressed image
	  cv::Mat decoded_image;
	  if(channels == 3)
	    {
	      decoded_image = cv::imdecode(cv::Mat(compressed_image), CV_LOAD_IMAGE_COLOR);
	      cv::cvtColor(decoded_image, Top_Image, CV_RGB2BGR);
	    }
	  else
	    {
	      decoded_image = cv::imdecode(cv::Mat(compressed_image), CV_LOAD_IMAGE_GRAYSCALE);
	      Top_Image = decoded_image;
	    }
	}
      if(!Top_F)
	{
	  std::cout<<"Get first Top image"<<std::endl;
	  //Top_Image_Def=Top_Image.clone();
	  Top_Image.copyTo(Top_Image_Def);
	  Top_F=true;
	}
      //cv::imshow("Top_Camera",Top_Image);

    }

  if(m_Flont_CameraIn.isNew())
    {
      while(!m_Flont_CameraIn.isEmpty())
	m_Flont_CameraIn.read();
    		
      int width = m_Flont_Camera.data.image.width;
      int height = m_Flont_Camera.data.image.height;
      int channels = (m_Flont_Camera.data.image.format == Img::CF_GRAY) ? 1 :
	(m_Flont_Camera.data.image.format == Img::CF_RGB || m_Flont_Camera.data.image.format == Img::CF_PNG || m_Flont_Camera.data.image.format == Img::CF_JPEG) ? 3 :
	(m_Flont_Camera.data.image.raw_data.length()/width/height);
      RTC_TRACE(("Capture image size %d x %d", width, height));
      RTC_TRACE(("Channels %d", channels));
		
      if(channels == 3)
	Flont_Image.create(height, width, CV_8UC3);
      else
	Flont_Image.create(height, width, CV_8UC1);		

      long data_length = m_Flont_Camera.data.image.raw_data.length();
      //long image_size = width * height * channels;

      if( m_Flont_Camera.data.image.format == Img::CF_RGB )
	{
	  for(int i=0; i<height; ++i)
	    memcpy(&Flont_Image.data[i*Flont_Image.step],&m_Flont_Camera.data.image.raw_data[i*width*channels],sizeof(unsigned char)*width*channels);
	  if(channels == 3)
	    cv::cvtColor(Flont_Image, Flont_Image, CV_RGB2BGR);
	}
      else if( m_Flont_Camera.data.image.format == Img::CF_JPEG || m_Flont_Camera.data.image.format == Img::CF_PNG )
	{
	  std::vector<uchar> compressed_image = std::vector<uchar>(data_length);
	  memcpy(&compressed_image[0], &m_Flont_Camera.data.image.raw_data[0], sizeof(unsigned char) * data_length);

	  //Decode received compressed image
	  cv::Mat decoded_image;
	  if(channels == 3)
	    {
	      decoded_image = cv::imdecode(cv::Mat(compressed_image), CV_LOAD_IMAGE_COLOR);
	      cv::cvtColor(decoded_image, Flont_Image, CV_RGB2BGR);
	    }
	  else
	    {
	      decoded_image = cv::imdecode(cv::Mat(compressed_image), CV_LOAD_IMAGE_GRAYSCALE);
	      Flont_Image = decoded_image;
	    }
	}
      if(!Flont_F)
	{
	  std::cout<<"Get first Flont image"<<std::endl;
	  //Flont_Image_Def=Flont_Image;
	  //Flont_Image_Def=Flont_Image.clone();
	  Flont_Image.copyTo(Flont_Image_Def);
	  cv::cvtColor(Flont_Image_Def,Flont_Image_Def,CV_BGR2GRAY);
	  Flont_F=true;
	}
      //cv::imshow("Flont_Camera",Flont_Image_Def);
    }

  if(Depth_F&&/*Top_F&&*/Flont_F)
    {
      /*	*/
      if(Flont_Image.channels()==3)
	{//グレースケールへの変換
	  cv::cvtColor(Flont_Image,Flont_Image,CV_BGR2GRAY);
	}

      cv::imshow("aaaa",Flont_Image);
      //桁落ち対策
      Flont_Image_Def.convertTo(Flont_Image_Def,CV_64F);
      Flont_Image.convertTo(Flont_Image,CV_64F);
	
      cv::Mat Difference_Flont;//=Flont_Image_Def-Flont_Image;
      cv::absdiff(Flont_Image_Def,Flont_Image,Difference_Flont);


      //二値化
      cv::threshold(Difference_Flont,Difference_Flont,100,255,CV_THRESH_BINARY/*|CV_THRESH_OTSU*/);
      //std::cout<<Difference_Flont<<std::endl;
      cv::imshow("deff",Difference_Flont);


      std::vector<std::vector<cv::Point> > contours;
      std::vector<cv::Vec4i> hierarchy;
      Difference_Flont.convertTo(Difference_Flont,CV_8U);
      //輪郭検出
      cv::findContours(Difference_Flont, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_TC89_L1);
      cv::Mat testMat;//=Difference_Flont.clone();
      cv::cvtColor(Difference_Flont,testMat,CV_GRAY2BGR);

      int max_level = 0;
      double b=0;
      cv::Point biggest_p1,biggest_p2,biggest_p3,biggest_p4;
      int contour_num=0;
	
      for(int i = 0; i < contours.size(); i++)
	{
	  // ある程度の面積が有るものだけに絞る
	  double a = cv::contourArea(contours[i],false);
	  if(a > 1500) {//面積の調整
	    //輪郭を直線近似する
	    std::vector<cv::Point> approx;
	    cv::approxPolyDP(cv::Mat(contours[i]), approx, 0.01 * cv::arcLength(contours[i], true), true);
	    // 矩形のみ取得
	    if (approx.size() == 4) {
	      cv::drawContours(testMat, contours, i, cv::Scalar(255, 0, 0, 255), 3, CV_AA, hierarchy, max_level);
	      //一番面積の大きい物のデータを保持
	      if(b<a)
		{//面積の保持
		  b=a;

		  //コーナーの保持
		  biggest_p1=approx[0];
		  biggest_p2=approx[1];
		  biggest_p3=approx[2];
		  biggest_p4=approx[3];
		  
		  contour_num++;
		  
		}
	      //std::cout<<" approx0 "<<approx[0]<<std::endl;
	    }
	  }
	  
	  //cv::drawContours(testMat, contours, i, cv::Scalar(255, 0, 0, 255), 3, CV_AA, hierarchy, max_level);
	}

      //std::cout<<" biggest_p1  "<<biggest_p1<<std::endl;
      cv::imshow("deff2",testMat);
      //cv::waitKey(300);
	
      if(contour_num==0)
	{
	  //物を発見できなかった場合処理を終了
	  // std::cout<<" No Object "<<std::endl;
	  return RTC::RTC_OK;
	}
      else if(contour_num>1)
	{
	  //物が複数あるか誤認識の可能性
	  std::cout<<" Find some object "<<std::endl;
	  m_Size.data[0]=0;
	}
      else if(contour_num==1)
	{
	  m_Size.data[0]=1;
	}
      //並び替えをして、内側にある点を用いることで、物体の奥行きを確認
      
      std::vector<int> X_point;
      X_point.push_back(biggest_p1.x);
      X_point.push_back(biggest_p2.x);
      X_point.push_back(biggest_p3.x);
      X_point.push_back(biggest_p4.x);
      std::sort(X_point.begin(),X_point.end());

	
      std::vector<int> Y_point;
      Y_point.push_back(biggest_p1.y);
      Y_point.push_back(biggest_p2.y);
      Y_point.push_back(biggest_p3.y);
      Y_point.push_back(biggest_p4.y);
      std::sort(Y_point.begin(),Y_point.end());
      //std::cout<<" time "<<X_point[1]<<" , "<<X_point[2]<<" , "<<Y_point[1]<<" , "<<Y_point[2]<<std::endl;
      double Height_sum=0;
      double Depth_sum=0;
      int sum_count=0;
      for(int x=X_point[1];x<X_point[2];x++)
	{
	  for(int y=Y_point[1];y<Y_point[2];y++)
	    {
	      /**/
	      if(Depth_Image.at<double>(y,x)!=0&&Depth_Image_Def.at<double>(y,x)!=0)
		{
		  Height_sum+=Depth_Image_Def.at<double>(y,x)-Depth_Image.at<double>(y,x);
		  Depth_sum+=Depth_Image.at<double>(y,x);
		  sum_count++;
		  //std::cout<<" x : "<<x<<" y : "<<y<<std::endl;
		}
		

	      //std::cout<<Depth_Image.at<double>(y,x)<<" , "<<Depth_Image_Def.at<double>(y,x)<<std::endl;
	    }
	}
      if(sum_count==0)
	{
	  std::cout<<"No Depth Data"<<std::endl;
	  return RTC::RTC_OK;
	}
      double Height_average=Height_sum/sum_count;
      double Depth_average=Depth_sum/sum_count;
      //std::cout<<" Height_average "<<Height_average<<std::endl;
      //標準偏差
      double sqr_sum=0;
      for(int x=X_point[1];x<X_point[2];x++)
	{
	  for(int y=Y_point[1];y<Y_point[2];y++)
	    {
	      /**/
	      if(Depth_Image.at<double>(y,x)!=0&&Depth_Image_Def.at<double>(y,x)!=0)
		{
		  double sqr_a = Height_average-(Depth_Image_Def.at<double>(y,x)-Depth_Image.at<double>(y,x));
		  sqr_sum=sqr_sum+sqr_a*sqr_a;
		    
		    
		  //std::cout<<" x : "<<x<<" y : "<<y<<std::endl;
		}
		

	      //std::cout<<Depth_Image.at<double>(y,x)<<" , "<<Depth_Image_Def.at<double>(y,x)<<std::endl;
	    }
	}
      double variance=sqr_sum/sum_count;
      double sd=std::sqrt(variance);
      std::cout<<" sd : "<<sd<<std::endl;
      if(sd>0.5)
	{
	  //上面が凸凹の場合
	  std::cout<<" Not Appropriate object "<<std::endl;
	  m_Size.data[0]=0;
	}
      //位置の計算
      double Meter_p1[2],Meter_p2[2],Meter_p3[2],Meter_p4[2];
      //double Meter;
      Meter_p1[0]=(double)(biggest_p1.x-m_Flont_Camera.data.intrinsic.matrix_element[1])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[0];
      Meter_p1[1]=(double)(biggest_p1.y-m_Flont_Camera.data.intrinsic.matrix_element[3])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[2];

      std::cout<<" Heigt_average "<<Height_average<<std::endl;
      std::cout<<" p1: "<<Meter_p1[0]<<","<<Meter_p1[1]<<std::endl;
	
      Meter_p2[0]=(biggest_p2.x-m_Flont_Camera.data.intrinsic.matrix_element[1])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[0];
      Meter_p2[1]=(biggest_p2.y-m_Flont_Camera.data.intrinsic.matrix_element[3])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[2];
      std::cout<<" p2: "<<Meter_p2[0]<<","<<Meter_p3[1]<<std::endl;

      Meter_p3[0]=(biggest_p3.x-m_Flont_Camera.data.intrinsic.matrix_element[1])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[0];
      Meter_p3[1]=(biggest_p3.y-m_Flont_Camera.data.intrinsic.matrix_element[3])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[2];
      std::cout<<" p3: "<<Meter_p3[0]<<","<<Meter_p3[1]<<std::endl;
	
      Meter_p4[0]=(biggest_p4.x-m_Flont_Camera.data.intrinsic.matrix_element[1])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[0];
      Meter_p4[1]=(biggest_p4.y-m_Flont_Camera.data.intrinsic.matrix_element[3])*Depth_average/m_Flont_Camera.data.intrinsic.matrix_element[2];
      std::cout<<" p4: "<<Meter_p4[0]<<","<<Meter_p4[1]<<std::endl;


      //ポイントから距離への変換
      std::vector<double>length_v;

      length_v.push_back(std::sqrt(std::pow(Meter_p1[0]-Meter_p2[0],2)+std::pow(Meter_p1[1]-Meter_p2[1],2)));
      length_v.push_back(std::sqrt(std::pow(Meter_p1[0]-Meter_p3[0],2)+std::pow(Meter_p1[1]-Meter_p3[1],2)));
      length_v.push_back(std::sqrt(std::pow(Meter_p1[0]-Meter_p4[0],2)+std::pow(Meter_p1[1]-Meter_p4[1],2)));
	

      std::sort(length_v.begin(),length_v.end());

      std::cout<<"1:"<<length_v[0]<<std::endl;
      std::cout<<"2:"<<length_v[1]<<std::endl;
      std::cout<<"3:"<<length_v[2]<<std::endl;

      //寸法の格納
      m_Size.data[1]=length_v[0];//長さ
      m_Size.data[2]=length_v[1];//幅
      m_Size.data[3]=Height_average;//高さ

      m_SizeOut.write();
    }
  cv::waitKey(3);

  return RTC::RTC_OK;
}

/*
  RTC::ReturnCode_t Dim_measure::onAborting(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onError(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onReset(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onStateUpdate(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/

/*
  RTC::ReturnCode_t Dim_measure::onRateChanged(RTC::UniqueId ec_id)
  {
  return RTC::RTC_OK;
  }
*/



extern "C"
{
 
  void Dim_measureInit(RTC::Manager* manager)
  {
    coil::Properties profile(dim_measure_spec);
    manager->registerFactory(profile,
                             RTC::Create<Dim_measure>,
                             RTC::Delete<Dim_measure>);
  }
  
};


