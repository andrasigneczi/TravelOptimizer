/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINestedURI.idl
 */

#ifndef __gen_nsINestedURI_h__
#define __gen_nsINestedURI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsINestedURI */
#define NS_INESTEDURI_IID_STR "6de2c874-796c-46bf-b57f-0d7bd7d6cab0"

#define NS_INESTEDURI_IID \
  {0x6de2c874, 0x796c, 0x46bf, \
    { 0xb5, 0x7f, 0x0d, 0x7b, 0xd7, 0xd6, 0xca, 0xb0 }}

class NS_NO_VTABLE nsINestedURI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INESTEDURI_IID)

  /* readonly attribute nsIURI innerURI; */
  NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) = 0;

  /* readonly attribute nsIURI innermostURI; */
  NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINestedURI, NS_INESTEDURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINESTEDURI \
  NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) override; \
  NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINESTEDURI(_to) \
  NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) override { return _to GetInnerURI(aInnerURI); } \
  NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) override { return _to GetInnermostURI(aInnermostURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINESTEDURI(_to) \
  NS_IMETHOD GetInnerURI(nsIURI * *aInnerURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerURI(aInnerURI); } \
  NS_IMETHOD GetInnermostURI(nsIURI * *aInnermostURI) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnermostURI(aInnermostURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNestedURI : public nsINestedURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINESTEDURI

  nsNestedURI();

private:
  ~nsNestedURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsNestedURI, nsINestedURI)

nsNestedURI::nsNestedURI()
{
  /* member initializers and constructor code */
}

nsNestedURI::~nsNestedURI()
{
  /* destructor code */
}

/* readonly attribute nsIURI innerURI; */
NS_IMETHODIMP nsNestedURI::GetInnerURI(nsIURI * *aInnerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI innermostURI; */
NS_IMETHODIMP nsNestedURI::GetInnermostURI(nsIURI * *aInnermostURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINestedURI_h__ */
