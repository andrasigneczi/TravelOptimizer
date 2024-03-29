/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLObjectElement.idl
 */

#ifndef __gen_nsIDOMHTMLObjectElement_h__
#define __gen_nsIDOMHTMLObjectElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLObjectElement */
#define NS_IDOMHTMLOBJECTELEMENT_IID_STR "baf443d2-da5d-40c9-be3c-c65a69a25250"

#define NS_IDOMHTMLOBJECTELEMENT_IID \
  {0xbaf443d2, 0xda5d, 0x40c9, \
    { 0xbe, 0x3c, 0xc6, 0x5a, 0x69, 0xa2, 0x52, 0x50 }}

class NS_NO_VTABLE nsIDOMHTMLObjectElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOBJECTELEMENT_IID)

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) = 0;

  /* attribute DOMString code; */
  NS_IMETHOD GetCode(nsAString & aCode) = 0;
  NS_IMETHOD SetCode(const nsAString & aCode) = 0;

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString archive; */
  NS_IMETHOD GetArchive(nsAString & aArchive) = 0;
  NS_IMETHOD SetArchive(const nsAString & aArchive) = 0;

  /* attribute DOMString border; */
  NS_IMETHOD GetBorder(nsAString & aBorder) = 0;
  NS_IMETHOD SetBorder(const nsAString & aBorder) = 0;

  /* attribute DOMString codeBase; */
  NS_IMETHOD GetCodeBase(nsAString & aCodeBase) = 0;
  NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) = 0;

  /* attribute DOMString codeType; */
  NS_IMETHOD GetCodeType(nsAString & aCodeType) = 0;
  NS_IMETHOD SetCodeType(const nsAString & aCodeType) = 0;

  /* attribute DOMString data; */
  NS_IMETHOD GetData(nsAString & aData) = 0;
  NS_IMETHOD SetData(const nsAString & aData) = 0;

  /* attribute boolean declare; */
  NS_IMETHOD GetDeclare(bool *aDeclare) = 0;
  NS_IMETHOD SetDeclare(bool aDeclare) = 0;

  /* attribute DOMString height; */
  NS_IMETHOD GetHeight(nsAString & aHeight) = 0;
  NS_IMETHOD SetHeight(const nsAString & aHeight) = 0;

  /* attribute long hspace; */
  NS_IMETHOD GetHspace(int32_t *aHspace) = 0;
  NS_IMETHOD SetHspace(int32_t aHspace) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString standby; */
  NS_IMETHOD GetStandby(nsAString & aStandby) = 0;
  NS_IMETHOD SetStandby(const nsAString & aStandby) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString useMap; */
  NS_IMETHOD GetUseMap(nsAString & aUseMap) = 0;
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) = 0;

  /* attribute long vspace; */
  NS_IMETHOD GetVspace(int32_t *aVspace) = 0;
  NS_IMETHOD SetVspace(int32_t aVspace) = 0;

  /* attribute DOMString width; */
  NS_IMETHOD GetWidth(nsAString & aWidth) = 0;
  NS_IMETHOD SetWidth(const nsAString & aWidth) = 0;

  /* readonly attribute nsIDOMDocument contentDocument; */
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) = 0;

  /* readonly attribute boolean willValidate; */
  NS_IMETHOD GetWillValidate(bool *aWillValidate) = 0;

  /* readonly attribute nsIDOMValidityState validity; */
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) = 0;

  /* readonly attribute DOMString validationMessage; */
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) = 0;

  /* boolean checkValidity (); */
  NS_IMETHOD CheckValidity(bool *_retval) = 0;

  /* void setCustomValidity (in DOMString error); */
  NS_IMETHOD SetCustomValidity(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLObjectElement, NS_IDOMHTMLOBJECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOBJECTELEMENT \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) override; \
  NS_IMETHOD GetCode(nsAString & aCode) override; \
  NS_IMETHOD SetCode(const nsAString & aCode) override; \
  NS_IMETHOD GetAlign(nsAString & aAlign) override; \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override; \
  NS_IMETHOD GetArchive(nsAString & aArchive) override; \
  NS_IMETHOD SetArchive(const nsAString & aArchive) override; \
  NS_IMETHOD GetBorder(nsAString & aBorder) override; \
  NS_IMETHOD SetBorder(const nsAString & aBorder) override; \
  NS_IMETHOD GetCodeBase(nsAString & aCodeBase) override; \
  NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) override; \
  NS_IMETHOD GetCodeType(nsAString & aCodeType) override; \
  NS_IMETHOD SetCodeType(const nsAString & aCodeType) override; \
  NS_IMETHOD GetData(nsAString & aData) override; \
  NS_IMETHOD SetData(const nsAString & aData) override; \
  NS_IMETHOD GetDeclare(bool *aDeclare) override; \
  NS_IMETHOD SetDeclare(bool aDeclare) override; \
  NS_IMETHOD GetHeight(nsAString & aHeight) override; \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override; \
  NS_IMETHOD GetHspace(int32_t *aHspace) override; \
  NS_IMETHOD SetHspace(int32_t aHspace) override; \
  NS_IMETHOD GetName(nsAString & aName) override; \
  NS_IMETHOD SetName(const nsAString & aName) override; \
  NS_IMETHOD GetStandby(nsAString & aStandby) override; \
  NS_IMETHOD SetStandby(const nsAString & aStandby) override; \
  NS_IMETHOD GetType(nsAString & aType) override; \
  NS_IMETHOD SetType(const nsAString & aType) override; \
  NS_IMETHOD GetUseMap(nsAString & aUseMap) override; \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) override; \
  NS_IMETHOD GetVspace(int32_t *aVspace) override; \
  NS_IMETHOD SetVspace(int32_t aVspace) override; \
  NS_IMETHOD GetWidth(nsAString & aWidth) override; \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override; \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) override; \
  NS_IMETHOD GetWillValidate(bool *aWillValidate) override; \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) override; \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) override; \
  NS_IMETHOD CheckValidity(bool *_retval) override; \
  NS_IMETHOD SetCustomValidity(const nsAString & error) override; 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOBJECTELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) override { return _to GetForm(aForm); } \
  NS_IMETHOD GetCode(nsAString & aCode) override { return _to GetCode(aCode); } \
  NS_IMETHOD SetCode(const nsAString & aCode) override { return _to SetCode(aCode); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) override { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetArchive(nsAString & aArchive) override { return _to GetArchive(aArchive); } \
  NS_IMETHOD SetArchive(const nsAString & aArchive) override { return _to SetArchive(aArchive); } \
  NS_IMETHOD GetBorder(nsAString & aBorder) override { return _to GetBorder(aBorder); } \
  NS_IMETHOD SetBorder(const nsAString & aBorder) override { return _to SetBorder(aBorder); } \
  NS_IMETHOD GetCodeBase(nsAString & aCodeBase) override { return _to GetCodeBase(aCodeBase); } \
  NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) override { return _to SetCodeBase(aCodeBase); } \
  NS_IMETHOD GetCodeType(nsAString & aCodeType) override { return _to GetCodeType(aCodeType); } \
  NS_IMETHOD SetCodeType(const nsAString & aCodeType) override { return _to SetCodeType(aCodeType); } \
  NS_IMETHOD GetData(nsAString & aData) override { return _to GetData(aData); } \
  NS_IMETHOD SetData(const nsAString & aData) override { return _to SetData(aData); } \
  NS_IMETHOD GetDeclare(bool *aDeclare) override { return _to GetDeclare(aDeclare); } \
  NS_IMETHOD SetDeclare(bool aDeclare) override { return _to SetDeclare(aDeclare); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) override { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetHspace(int32_t *aHspace) override { return _to GetHspace(aHspace); } \
  NS_IMETHOD SetHspace(int32_t aHspace) override { return _to SetHspace(aHspace); } \
  NS_IMETHOD GetName(nsAString & aName) override { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return _to SetName(aName); } \
  NS_IMETHOD GetStandby(nsAString & aStandby) override { return _to GetStandby(aStandby); } \
  NS_IMETHOD SetStandby(const nsAString & aStandby) override { return _to SetStandby(aStandby); } \
  NS_IMETHOD GetType(nsAString & aType) override { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return _to SetType(aType); } \
  NS_IMETHOD GetUseMap(nsAString & aUseMap) override { return _to GetUseMap(aUseMap); } \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) override { return _to SetUseMap(aUseMap); } \
  NS_IMETHOD GetVspace(int32_t *aVspace) override { return _to GetVspace(aVspace); } \
  NS_IMETHOD SetVspace(int32_t aVspace) override { return _to SetVspace(aVspace); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) override { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) override { return _to GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetWillValidate(bool *aWillValidate) override { return _to GetWillValidate(aWillValidate); } \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) override { return _to GetValidity(aValidity); } \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) override { return _to GetValidationMessage(aValidationMessage); } \
  NS_IMETHOD CheckValidity(bool *_retval) override { return _to CheckValidity(_retval); } \
  NS_IMETHOD SetCustomValidity(const nsAString & error) override { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOBJECTELEMENT(_to) \
  NS_IMETHOD GetForm(nsIDOMHTMLFormElement * *aForm) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_IMETHOD GetCode(nsAString & aCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_IMETHOD SetCode(const nsAString & aCode) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCode(aCode); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetArchive(nsAString & aArchive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArchive(aArchive); } \
  NS_IMETHOD SetArchive(const nsAString & aArchive) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetArchive(aArchive); } \
  NS_IMETHOD GetBorder(nsAString & aBorder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorder(aBorder); } \
  NS_IMETHOD SetBorder(const nsAString & aBorder) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBorder(aBorder); } \
  NS_IMETHOD GetCodeBase(nsAString & aCodeBase) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodeBase(aCodeBase); } \
  NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCodeBase(aCodeBase); } \
  NS_IMETHOD GetCodeType(nsAString & aCodeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodeType(aCodeType); } \
  NS_IMETHOD SetCodeType(const nsAString & aCodeType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCodeType(aCodeType); } \
  NS_IMETHOD GetData(nsAString & aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD SetData(const nsAString & aData) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aData); } \
  NS_IMETHOD GetDeclare(bool *aDeclare) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeclare(aDeclare); } \
  NS_IMETHOD SetDeclare(bool aDeclare) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDeclare(aDeclare); } \
  NS_IMETHOD GetHeight(nsAString & aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(const nsAString & aHeight) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetHspace(int32_t *aHspace) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHspace(aHspace); } \
  NS_IMETHOD SetHspace(int32_t aHspace) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHspace(aHspace); } \
  NS_IMETHOD GetName(nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetStandby(nsAString & aStandby) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStandby(aStandby); } \
  NS_IMETHOD SetStandby(const nsAString & aStandby) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStandby(aStandby); } \
  NS_IMETHOD GetType(nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetUseMap(nsAString & aUseMap) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseMap(aUseMap); } \
  NS_IMETHOD SetUseMap(const nsAString & aUseMap) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseMap(aUseMap); } \
  NS_IMETHOD GetVspace(int32_t *aVspace) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVspace(aVspace); } \
  NS_IMETHOD SetVspace(int32_t aVspace) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVspace(aVspace); } \
  NS_IMETHOD GetWidth(nsAString & aWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(const nsAString & aWidth) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetWillValidate(bool *aWillValidate) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_IMETHOD GetValidity(nsIDOMValidityState * *aValidity) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) override { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_IMETHOD CheckValidity(bool *_retval) override { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_IMETHOD SetCustomValidity(const nsAString & error) override { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLObjectElement : public nsIDOMHTMLObjectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOBJECTELEMENT

  nsDOMHTMLObjectElement();

private:
  ~nsDOMHTMLObjectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS(nsDOMHTMLObjectElement, nsIDOMHTMLObjectElement)

nsDOMHTMLObjectElement::nsDOMHTMLObjectElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLObjectElement::~nsDOMHTMLObjectElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetForm(nsIDOMHTMLFormElement * *aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString code; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCode(nsAString & aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCode(const nsAString & aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString archive; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetArchive(nsAString & aArchive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetArchive(const nsAString & aArchive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString border; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetBorder(nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetBorder(const nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString codeBase; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCodeBase(nsAString & aCodeBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCodeBase(const nsAString & aCodeBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString codeType; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCodeType(nsAString & aCodeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCodeType(const nsAString & aCodeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString data; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetData(const nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean declare; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetDeclare(bool *aDeclare)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetDeclare(bool aDeclare)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString height; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetHeight(nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetHeight(const nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long hspace; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetHspace(int32_t *aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetHspace(int32_t aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString standby; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetStandby(nsAString & aStandby)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetStandby(const nsAString & aStandby)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString useMap; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetUseMap(nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetUseMap(const nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long vspace; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetVspace(int32_t *aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetVspace(int32_t aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString width; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetWidth(nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetWidth(const nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument contentDocument; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetContentDocument(nsIDOMDocument * *aContentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetWillValidate(bool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetValidity(nsIDOMValidityState * *aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLObjectElement::CheckValidity(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLObjectElement_h__ */
