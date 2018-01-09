// -*-C++-*-
/*!
 * @file  PrintDelivaryInterfaceSVC_impl.h
 * @brief Service implementation header of PrintDelivaryInterface.idl
 *
 */

#include "BasicDataTypeSkel.h"

#include "PrintDelivaryInterfaceSkel.h"

#ifndef PRINTDELIVARYINTERFACESVC_IMPL_H
#define PRINTDELIVARYINTERFACESVC_IMPL_H
 
/*!
 * @class PrintDeriveryInterfaceSVC_impl
 * Example class implementing IDL interface PrintDelivery::PrintDeriveryInterface
 */
class PrintDelivery_PrintDeriveryInterfaceSVC_impl
 : public virtual POA_PrintDelivery::PrintDeriveryInterface,
   public virtual PortableServer::RefCountServantBase
{
 private:
   // Make sure all instances are built on the heap by making the
   // destructor non-public
   //virtual ~PrintDeriveryInterfaceSVC_impl();

 public:
  /*!
   * @brief standard constructor
   */
	 PrintDelivery_PrintDeriveryInterfaceSVC_impl();
  /*!
   * @brief destructor
   */
   virtual ~PrintDelivery_PrintDeriveryInterfaceSVC_impl();

   // attributes and operations
   PrintDelivery::RETURN_ID* PrintDeliveryData(const PrintDelivery::PrintData& data);

};



#endif // PRINTDELIVARYINTERFACESVC_IMPL_H


