// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: register_ack.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_register_5fack_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_register_5fack_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_register_5fack_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_register_5fack_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_register_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class RegisterAck;
class RegisterAckDefaultTypeInternal;
extern RegisterAckDefaultTypeInternal _RegisterAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::RegisterAck* Arena::CreateMaybeMessage<::chatroom::msgpb::RegisterAck>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class RegisterAck PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.RegisterAck) */ {
 public:
  inline RegisterAck() : RegisterAck(nullptr) {};
  virtual ~RegisterAck();

  RegisterAck(const RegisterAck& from);
  RegisterAck(RegisterAck&& from) noexcept
    : RegisterAck() {
    *this = ::std::move(from);
  }

  inline RegisterAck& operator=(const RegisterAck& from) {
    CopyFrom(from);
    return *this;
  }
  inline RegisterAck& operator=(RegisterAck&& from) noexcept {
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
  static const RegisterAck& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegisterAck* internal_default_instance() {
    return reinterpret_cast<const RegisterAck*>(
               &_RegisterAck_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(RegisterAck& a, RegisterAck& b) {
    a.Swap(&b);
  }
  inline void Swap(RegisterAck* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(RegisterAck* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline RegisterAck* New() const final {
    return CreateMaybeMessage<RegisterAck>(nullptr);
  }

  RegisterAck* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RegisterAck>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RegisterAck& from);
  void MergeFrom(const RegisterAck& from);
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
  void InternalSwap(RegisterAck* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.RegisterAck";
  }
  protected:
  explicit RegisterAck(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_register_5fack_2eproto);
    return ::descriptor_table_register_5fack_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kSuccessFieldNumber = 1,
    kAccountFieldNumber = 3,
  };
  // string errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  void set_errmsg(const std::string& value);
  void set_errmsg(std::string&& value);
  void set_errmsg(const char* value);
  void set_errmsg(const char* value, size_t size);
  std::string* mutable_errmsg();
  std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_errmsg();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_errmsg(
      std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // int32 account = 3;
  void clear_account();
  ::PROTOBUF_NAMESPACE_ID::int32 account() const;
  void set_account(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_account() const;
  void _internal_set_account(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.RegisterAck)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  bool success_;
  ::PROTOBUF_NAMESPACE_ID::int32 account_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_register_5fack_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegisterAck

// bool success = 1;
inline void RegisterAck::clear_success() {
  success_ = false;
}
inline bool RegisterAck::_internal_success() const {
  return success_;
}
inline bool RegisterAck::success() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.RegisterAck.success)
  return _internal_success();
}
inline void RegisterAck::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void RegisterAck::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.RegisterAck.success)
}

// string errmsg = 2;
inline void RegisterAck::clear_errmsg() {
  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& RegisterAck::errmsg() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.RegisterAck.errmsg)
  return _internal_errmsg();
}
inline void RegisterAck::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.RegisterAck.errmsg)
}
inline std::string* RegisterAck::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.RegisterAck.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& RegisterAck::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void RegisterAck::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void RegisterAck::set_errmsg(std::string&& value) {
  
  errmsg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.RegisterAck.errmsg)
}
inline void RegisterAck::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.RegisterAck.errmsg)
}
inline void RegisterAck::set_errmsg(const char* value,
    size_t size) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.RegisterAck.errmsg)
}
inline std::string* RegisterAck::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* RegisterAck::release_errmsg() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.RegisterAck.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void RegisterAck::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.RegisterAck.errmsg)
}
inline std::string* RegisterAck::unsafe_arena_release_errmsg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.RegisterAck.errmsg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return errmsg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void RegisterAck::unsafe_arena_set_allocated_errmsg(
    std::string* errmsg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      errmsg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.RegisterAck.errmsg)
}

// int32 account = 3;
inline void RegisterAck::clear_account() {
  account_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RegisterAck::_internal_account() const {
  return account_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RegisterAck::account() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.RegisterAck.account)
  return _internal_account();
}
inline void RegisterAck::_internal_set_account(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  account_ = value;
}
inline void RegisterAck::set_account(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_account(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.RegisterAck.account)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_register_5fack_2eproto