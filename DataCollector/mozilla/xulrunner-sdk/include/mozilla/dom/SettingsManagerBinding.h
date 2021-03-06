/* THIS FILE IS AUTOGENERATED FROM SettingsManager.webidl BY Codegen.py - DO NOT EDIT */

#ifndef mozilla_dom_SettingsManagerBinding_h
#define mozilla_dom_SettingsManagerBinding_h

#include "js/RootingAPI.h"
#include "jspubtd.h"
#include "mozilla/DOMEventTargetHelper.h"
#include "mozilla/ErrorResult.h"
#include "mozilla/dom/BindingDeclarations.h"
#include "mozilla/dom/CallbackFunction.h"
#include "mozilla/dom/CallbackInterface.h"
#include "mozilla/dom/Nullable.h"
#include "mozilla/dom/ToJSValue.h"
#include "nsWeakReference.h"

namespace mozilla {
namespace dom {

class DOMRequest;
class EventHandlerNonNull;
struct NativePropertyHooks;
class ProtoAndIfaceCache;
struct SettingChange;
struct SettingChangeAtoms;
class SettingChangeCallback;
class SettingsLock;
struct SettingsLockAtoms;
class SettingsManager;
struct SettingsManagerAtoms;

} // namespace dom
} // namespace mozilla

namespace mozilla {
namespace dom {

struct SettingChange : public DictionaryBase
{
  Optional<nsString> mSettingName;
  Optional<nsString> mSettingValue;

  SettingChange();

  explicit inline SettingChange(const FastDictionaryInitializer& )
  {
    // Do nothing here; this is used by our "Fast" subclass
  }

  explicit inline SettingChange(const SettingChange& aOther)
  {
    *this = aOther;
  }

  bool
  Init(JSContext* cx, JS::Handle<JS::Value> val, const char* sourceDescription = "Value", bool passedToJSImpl = false);

  bool
  Init(const nsAString& aJSON);

  bool
  ToObjectInternal(JSContext* cx, JS::MutableHandle<JS::Value> rval) const;

  bool
  ToJSON(nsAString& aJSON) const;

  void
  TraceDictionary(JSTracer* trc);

  void
  operator=(const SettingChange& aOther);

private:
  static bool
  InitIds(JSContext* cx, SettingChangeAtoms* atomsCache);
};

namespace binding_detail {
struct FastSettingChange : public SettingChange
{
  inline FastSettingChange()
    : SettingChange(FastDictionaryInitializer())
  {
    // Doesn't matter what int we pass to the parent constructor
  }
};
} // namespace binding_detail


class SettingChangeCallback : public CallbackFunction
{
public:
  explicit inline SettingChangeCallback(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackFunction(aCallback, aIncumbentGlobal)
  {
    MOZ_ASSERT(JS::IsCallable(mCallback));
  }

  explicit inline SettingChangeCallback(CallbackFunction* aOther)
    : CallbackFunction(aOther)
  {
  }

  template <typename T>
  inline void
  Call(const T& thisVal, const SettingChange& setting, ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr)
  {
    if (!aExecutionReason) {
      aExecutionReason = "SettingChangeCallback";
    }
    CallSetup s(this, aRv, aExecutionReason, aExceptionHandling, aCompartment);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    JS::Rooted<JS::Value> thisValJS(s.GetContext());
    if (!ToJSValue(s.GetContext(), thisVal, &thisValJS)) {
      aRv.Throw(NS_ERROR_FAILURE);
      return;
    }
    return Call(s.GetContext(), thisValJS, setting, aRv);
  }

  inline void
  Call(const SettingChange& setting, ErrorResult& aRv, const char* aExecutionReason = nullptr, ExceptionHandling aExceptionHandling = eReportExceptions, JSCompartment* aCompartment = nullptr)
  {
    if (!aExecutionReason) {
      aExecutionReason = "SettingChangeCallback";
    }
    CallSetup s(this, aRv, aExecutionReason, aExceptionHandling, aCompartment);
    if (!s.GetContext()) {
      aRv.Throw(NS_ERROR_UNEXPECTED);
      return;
    }
    return Call(s.GetContext(), JS::UndefinedHandleValue, setting, aRv);
  }

  inline bool
  operator==(const SettingChangeCallback& aOther) const
  {
    return CallbackFunction::operator==(aOther);
  }

private:
  void Call(JSContext* cx, JS::Handle<JS::Value> aThisVal, const SettingChange& setting, ErrorResult& aRv);
};


namespace SettingsLockBinding {

  typedef mozilla::dom::SettingsLock NativeType;

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

  bool
  ConstructorEnabled(JSContext* aCx, JS::Handle<JSObject*> aObj);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::SettingsLock* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace SettingsLockBinding



namespace SettingsManagerBinding {

  typedef mozilla::dom::SettingsManager NativeType;

  JSObject*
  ConstructNavigatorObject(JSContext* aCx, JS::Handle<JSObject*> aObj);

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

  bool
  ConstructorEnabled(JSContext* aCx, JS::Handle<JSObject*> aObj);

  const JSClass*
  GetJSClass();

  bool
  Wrap(JSContext* aCx, mozilla::dom::SettingsManager* aObject, nsWrapperCache* aCache, JS::Handle<JSObject*> aGivenProto, JS::MutableHandle<JSObject*> aReflector);

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

} // namespace SettingsManagerBinding



class SettingsLockJSImpl : public CallbackInterface
{
public:
  explicit inline SettingsLockJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<DOMRequest> Set(JS::Handle<JSObject*> settings, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> Get(const nsAString& name, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<DOMRequest> Clear(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const SettingsLockJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  bool GetClosed(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOnsettingstransactionsuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOnsettingstransactionfailure(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetOnsettingstransactionsuccess(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetOnsettingstransactionfailure(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, SettingsLockAtoms* atomsCache);
};


class SettingsLock final : public mozilla::DOMEventTargetHelper
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(SettingsLock, mozilla::DOMEventTargetHelper)

private:
  nsRefPtr<SettingsLockJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  SettingsLock(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~SettingsLock();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  bool GetClosed(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Set(JS::Handle<JSObject*> settings, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Get(const nsAString& name, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<DOMRequest> Clear(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOnsettingstransactionsuccess(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetOnsettingstransactionsuccess(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOnsettingstransactionfailure(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetOnsettingstransactionfailure(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


class SettingsManagerJSImpl : public CallbackInterface
{
public:
  explicit inline SettingsManagerJSImpl(JS::Handle<JSObject*> aCallback, nsIGlobalObject* aIncumbentGlobal)
    : CallbackInterface(aCallback, aIncumbentGlobal)
  {
  }

  already_AddRefed<SettingsLock> CreateLock(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void AddObserver(const nsAString& name, SettingChangeCallback& callback, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void RemoveObserver(const nsAString& name, SettingChangeCallback& callback, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  inline bool
  operator==(const SettingsManagerJSImpl& aOther) const
  {
    return CallbackInterface::operator==(aOther);
  }

  already_AddRefed<EventHandlerNonNull> GetOnsettingchange(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void SetOnsettingchange(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

private:
  static bool
  InitIds(JSContext* cx, SettingsManagerAtoms* atomsCache);
};


class SettingsManager final : public mozilla::DOMEventTargetHelper
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_CLASS_INHERITED(SettingsManager, mozilla::DOMEventTargetHelper)

private:
  nsRefPtr<SettingsManagerJSImpl> mImpl;
  nsCOMPtr<nsISupports> mParent;

public:
  SettingsManager(JS::Handle<JSObject*> aJSImplObject, nsIGlobalObject* aParent);

private:
  ~SettingsManager();

public:
  nsISupports* GetParentObject() const;

  virtual JSObject* WrapObject(JSContext* aCx, JS::Handle<JSObject*> aGivenProto) override;

  // Return a raw pointer here to avoid refcounting, but make sure it's safe (the object should be kept alive by the callee).
  already_AddRefed<SettingsLock> CreateLock(ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void AddObserver(const nsAString& name, SettingChangeCallback& callback, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  void RemoveObserver(const nsAString& name, SettingChangeCallback& callback, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  already_AddRefed<EventHandlerNonNull> GetOnsettingchange(ErrorResult& aRv, JSCompartment* aCompartment = nullptr) const;

  void SetOnsettingchange(EventHandlerNonNull* arg, ErrorResult& aRv, JSCompartment* aCompartment = nullptr);

  static bool
  _Create(JSContext* cx, unsigned argc, JS::Value* vp);
};


} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_SettingsManagerBinding_h
