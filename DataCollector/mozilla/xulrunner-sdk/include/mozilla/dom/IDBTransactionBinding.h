/* THIS FILE IS AUTOGENERATED FROM IDBTransaction.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_IDBTransactionBinding_h
#define mozilla_dom_IDBTransactionBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/Nullable.h"

namespace mozilla {
namespace dom {

struct NativePropertyHooks;
class ProtoAndIfaceCache;

namespace indexedDB {

class IDBTransaction;
struct IDBTransactionAtoms;

} // namespace indexedDB

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

enum class IDBTransactionMode : uint32_t {
  Readonly,
  Readwrite,
  Readwriteflush,
  Versionchange,
  EndGuard_
};

namespace IDBTransactionModeValues {
extern const EnumEntry strings[5];
} // namespace IDBTransactionModeValues


namespace IDBTransactionBinding {

  typedef mozilla::dom::indexedDB::IDBTransaction NativeType;

  // We declare this as an array so that retrieving a pointer to this
  // binding's property hooks only requires compile/link-time resolvable
  // address arithmetic.  Declaring it as a pointer instead would require
  // doing a run-time load to fetch a pointer to this binding's property
  // hooks.  And then structures which embedded a pointer to this structure
  // would require a run-time load for proper initialization, which would
  // then induce static constructors.  Lots of static constructors.
  extern const NativePropertyHooks sNativePropertyHooks[];

  JSObject*
  DefineDOMInterface(JSContext* aCx, JS::Handle<JSObject*> aGlobal, JS::Handle<jsid> id, bool aDefineOnGlobal);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::indexedDB::IDBTransaction* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

  template <class T>
  inline JSObject* Wrap(JSContext* aCx, T* aObject, JS::Handle<JSObject*> aGivenProto)
  {
    JS::Rooted<JSObject*> reflector(aCx);
    return Wrap(aCx, aObject, aObject, aGivenProto, &reflector) ? reflector.get() : nullptr;
  }

  void
  CreateInterfaceObjects(JSContext* aCx, JS::Handle<JSObject*> aGlobal, ProtoAndIfaceCache& aProtoAndIfaceCache, bool aDefineOnGlobal);

  JS::Handle<JSObject*>
  GetProtoObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

  JS::Handle<JSObject*>
  GetConstructorObjectHandle(JSContext* aCx, JS::Handle<JSObject*> aGlobal, bool aDefineOnGlobal = true);

  JSObject*
  GetConstructorObject(JSContext* aCx, JS::Handle<JSObject*> aGlobal);

} // namespace IDBTransactionBinding



} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_IDBTransactionBinding_h