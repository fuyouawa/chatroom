// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgpb/join_group_ack.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msgpb_2fjoin_5fgroup_5fack_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msgpb_2fjoin_5fgroup_5fack_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_msgpb_2fjoin_5fgroup_5fack_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msgpb_2fjoin_5fgroup_5fack_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msgpb_2fjoin_5fgroup_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class JoinGroupAck;
class JoinGroupAckDefaultTypeInternal;
extern JoinGroupAckDefaultTypeInternal _JoinGroupAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::JoinGroupAck* Arena::CreateMaybeMessage<::chatroom::msgpb::JoinGroupAck>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class JoinGroupAck PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.JoinGroupAck) */ {
 public:
  inline JoinGroupAck() : JoinGroupAck(nullptr) {};
  virtual ~JoinGroupAck();

  JoinGroupAck(const JoinGroupAck& from);
  JoinGroupAck(JoinGroupAck&& from) noexcept
    : JoinGroupAck() {
    *this = ::std::move(from);
  }

  inline JoinGroupAck& operator=(const JoinGroupAck& from) {
    CopyFrom(from);
    return *this;
  }
  inline JoinGroupAck& operator=(JoinGroupAck&& from) noexcept {
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
  static const JoinGroupAck& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const JoinGroupAck* internal_default_instance() {
    return reinterpret_cast<const JoinGroupAck*>(
               &_JoinGroupAck_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(JoinGroupAck& a, JoinGroupAck& b) {
    a.Swap(&b);
  }
  inline void Swap(JoinGroupAck* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(JoinGroupAck* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline JoinGroupAck* New() const final {
    return CreateMaybeMessage<JoinGroupAck>(nullptr);
  }

  JoinGroupAck* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<JoinGroupAck>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const JoinGroupAck& from);
  void MergeFrom(const JoinGroupAck& from);
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
  void InternalSwap(JoinGroupAck* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.JoinGroupAck";
  }
  protected:
  explicit JoinGroupAck(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msgpb_2fjoin_5fgroup_5fack_2eproto);
    return ::descriptor_table_msgpb_2fjoin_5fgroup_5fack_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kGroupNameFieldNumber = 3,
    kSuccessFieldNumber = 1,
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

  // string group_name = 3;
  void clear_group_name();
  const std::string& group_name() const;
  void set_group_name(const std::string& value);
  void set_group_name(std::string&& value);
  void set_group_name(const char* value);
  void set_group_name(const char* value, size_t size);
  std::string* mutable_group_name();
  std::string* release_group_name();
  void set_allocated_group_name(std::string* group_name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_group_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_group_name(
      std::string* group_name);
  private:
  const std::string& _internal_group_name() const;
  void _internal_set_group_name(const std::string& value);
  std::string* _internal_mutable_group_name();
  public:

  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.JoinGroupAck)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr group_name_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msgpb_2fjoin_5fgroup_5fack_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// JoinGroupAck

// bool success = 1;
inline void JoinGroupAck::clear_success() {
  success_ = false;
}
inline bool JoinGroupAck::_internal_success() const {
  return success_;
}
inline bool JoinGroupAck::success() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.JoinGroupAck.success)
  return _internal_success();
}
inline void JoinGroupAck::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void JoinGroupAck::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.JoinGroupAck.success)
}

// string errmsg = 2;
inline void JoinGroupAck::clear_errmsg() {
  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& JoinGroupAck::errmsg() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.JoinGroupAck.errmsg)
  return _internal_errmsg();
}
inline void JoinGroupAck::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.JoinGroupAck.errmsg)
}
inline std::string* JoinGroupAck::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.JoinGroupAck.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& JoinGroupAck::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void JoinGroupAck::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void JoinGroupAck::set_errmsg(std::string&& value) {
  
  errmsg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.JoinGroupAck.errmsg)
}
inline void JoinGroupAck::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.JoinGroupAck.errmsg)
}
inline void JoinGroupAck::set_errmsg(const char* value,
    size_t size) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.JoinGroupAck.errmsg)
}
inline std::string* JoinGroupAck::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* JoinGroupAck::release_errmsg() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.JoinGroupAck.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void JoinGroupAck::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.JoinGroupAck.errmsg)
}
inline std::string* JoinGroupAck::unsafe_arena_release_errmsg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.JoinGroupAck.errmsg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return errmsg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void JoinGroupAck::unsafe_arena_set_allocated_errmsg(
    std::string* errmsg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      errmsg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.JoinGroupAck.errmsg)
}

// string group_name = 3;
inline void JoinGroupAck::clear_group_name() {
  group_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& JoinGroupAck::group_name() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.JoinGroupAck.group_name)
  return _internal_group_name();
}
inline void JoinGroupAck::set_group_name(const std::string& value) {
  _internal_set_group_name(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.JoinGroupAck.group_name)
}
inline std::string* JoinGroupAck::mutable_group_name() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.JoinGroupAck.group_name)
  return _internal_mutable_group_name();
}
inline const std::string& JoinGroupAck::_internal_group_name() const {
  return group_name_.Get();
}
inline void JoinGroupAck::_internal_set_group_name(const std::string& value) {
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void JoinGroupAck::set_group_name(std::string&& value) {
  
  group_name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.JoinGroupAck.group_name)
}
inline void JoinGroupAck::set_group_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.JoinGroupAck.group_name)
}
inline void JoinGroupAck::set_group_name(const char* value,
    size_t size) {
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.JoinGroupAck.group_name)
}
inline std::string* JoinGroupAck::_internal_mutable_group_name() {
  
  return group_name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* JoinGroupAck::release_group_name() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.JoinGroupAck.group_name)
  return group_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void JoinGroupAck::set_allocated_group_name(std::string* group_name) {
  if (group_name != nullptr) {
    
  } else {
    
  }
  group_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), group_name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.JoinGroupAck.group_name)
}
inline std::string* JoinGroupAck::unsafe_arena_release_group_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.JoinGroupAck.group_name)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return group_name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void JoinGroupAck::unsafe_arena_set_allocated_group_name(
    std::string* group_name) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (group_name != nullptr) {
    
  } else {
    
  }
  group_name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      group_name, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.JoinGroupAck.group_name)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msgpb_2fjoin_5fgroup_5fack_2eproto
