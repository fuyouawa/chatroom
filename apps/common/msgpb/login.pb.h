// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: login.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_login_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_login_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_login_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_login_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_login_2eproto;
namespace chatroom {
namespace msgpb {
class Login;
class LoginDefaultTypeInternal;
extern LoginDefaultTypeInternal _Login_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::Login* Arena::CreateMaybeMessage<::chatroom::msgpb::Login>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class Login PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.Login) */ {
 public:
  inline Login() : Login(nullptr) {};
  virtual ~Login();

  Login(const Login& from);
  Login(Login&& from) noexcept
    : Login() {
    *this = ::std::move(from);
  }

  inline Login& operator=(const Login& from) {
    CopyFrom(from);
    return *this;
  }
  inline Login& operator=(Login&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Login& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Login* internal_default_instance() {
    return reinterpret_cast<const Login*>(
               &_Login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Login& a, Login& b) {
    a.Swap(&b);
  }
  inline void Swap(Login* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Login* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Login* New() const final {
    return CreateMaybeMessage<Login>(nullptr);
  }

  Login* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Login>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Login& from);
  void MergeFrom(const Login& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Login* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.Login";
  }
  protected:
  explicit Login(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_login_2eproto);
    return ::descriptor_table_login_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPasswordFieldNumber = 2,
    kUserIdFieldNumber = 1,
  };
  // string password = 2;
  void clear_password();
  const std::string& password() const;
  void set_password(const std::string& value);
  void set_password(std::string&& value);
  void set_password(const char* value);
  void set_password(const char* value, size_t size);
  std::string* mutable_password();
  std::string* release_password();
  void set_allocated_password(std::string* password);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_password();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_password(
      std::string* password);
  private:
  const std::string& _internal_password() const;
  void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // uint32 user_id = 1;
  void clear_user_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id() const;
  void set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_user_id() const;
  void _internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.Login)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_login_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Login

// uint32 user_id = 1;
inline void Login::clear_user_id() {
  user_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Login::_internal_user_id() const {
  return user_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Login::user_id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.Login.user_id)
  return _internal_user_id();
}
inline void Login::_internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  user_id_ = value;
}
inline void Login::set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.Login.user_id)
}

// string password = 2;
inline void Login::clear_password() {
  password_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Login::password() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.Login.password)
  return _internal_password();
}
inline void Login::set_password(const std::string& value) {
  _internal_set_password(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.Login.password)
}
inline std::string* Login::mutable_password() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.Login.password)
  return _internal_mutable_password();
}
inline const std::string& Login::_internal_password() const {
  return password_.Get();
}
inline void Login::_internal_set_password(const std::string& value) {
  
  password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Login::set_password(std::string&& value) {
  
  password_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.Login.password)
}
inline void Login::set_password(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.Login.password)
}
inline void Login::set_password(const char* value,
    size_t size) {
  
  password_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.Login.password)
}
inline std::string* Login::_internal_mutable_password() {
  
  return password_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Login::release_password() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.Login.password)
  return password_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Login::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), password,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.Login.password)
}
inline std::string* Login::unsafe_arena_release_password() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.Login.password)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return password_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void Login::unsafe_arena_set_allocated_password(
    std::string* password) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (password != nullptr) {
    
  } else {
    
  }
  password_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      password, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.Login.password)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_login_2eproto
