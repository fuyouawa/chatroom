// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgpb/send_msg_to_group.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto;
namespace chatroom {
namespace msgpb {
class SendMsgToGroup;
class SendMsgToGroupDefaultTypeInternal;
extern SendMsgToGroupDefaultTypeInternal _SendMsgToGroup_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::SendMsgToGroup* Arena::CreateMaybeMessage<::chatroom::msgpb::SendMsgToGroup>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class SendMsgToGroup PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.SendMsgToGroup) */ {
 public:
  inline SendMsgToGroup() : SendMsgToGroup(nullptr) {};
  virtual ~SendMsgToGroup();

  SendMsgToGroup(const SendMsgToGroup& from);
  SendMsgToGroup(SendMsgToGroup&& from) noexcept
    : SendMsgToGroup() {
    *this = ::std::move(from);
  }

  inline SendMsgToGroup& operator=(const SendMsgToGroup& from) {
    CopyFrom(from);
    return *this;
  }
  inline SendMsgToGroup& operator=(SendMsgToGroup&& from) noexcept {
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
  static const SendMsgToGroup& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SendMsgToGroup* internal_default_instance() {
    return reinterpret_cast<const SendMsgToGroup*>(
               &_SendMsgToGroup_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SendMsgToGroup& a, SendMsgToGroup& b) {
    a.Swap(&b);
  }
  inline void Swap(SendMsgToGroup* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SendMsgToGroup* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SendMsgToGroup* New() const final {
    return CreateMaybeMessage<SendMsgToGroup>(nullptr);
  }

  SendMsgToGroup* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SendMsgToGroup>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SendMsgToGroup& from);
  void MergeFrom(const SendMsgToGroup& from);
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
  void InternalSwap(SendMsgToGroup* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.SendMsgToGroup";
  }
  protected:
  explicit SendMsgToGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto);
    return ::descriptor_table_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 3,
    kUserIdFieldNumber = 1,
    kGroupIdFieldNumber = 2,
  };
  // string msg = 3;
  void clear_msg();
  const std::string& msg() const;
  void set_msg(const std::string& value);
  void set_msg(std::string&& value);
  void set_msg(const char* value);
  void set_msg(const char* value, size_t size);
  std::string* mutable_msg();
  std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_msg();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_msg(
      std::string* msg);
  private:
  const std::string& _internal_msg() const;
  void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // uint32 user_id = 1;
  void clear_user_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id() const;
  void set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_user_id() const;
  void _internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 group_id = 2;
  void clear_group_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 group_id() const;
  void set_group_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_group_id() const;
  void _internal_set_group_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.SendMsgToGroup)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id_;
  ::PROTOBUF_NAMESPACE_ID::uint32 group_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SendMsgToGroup

// uint32 user_id = 1;
inline void SendMsgToGroup::clear_user_id() {
  user_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendMsgToGroup::_internal_user_id() const {
  return user_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendMsgToGroup::user_id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.SendMsgToGroup.user_id)
  return _internal_user_id();
}
inline void SendMsgToGroup::_internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  user_id_ = value;
}
inline void SendMsgToGroup::set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.SendMsgToGroup.user_id)
}

// uint32 group_id = 2;
inline void SendMsgToGroup::clear_group_id() {
  group_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendMsgToGroup::_internal_group_id() const {
  return group_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SendMsgToGroup::group_id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.SendMsgToGroup.group_id)
  return _internal_group_id();
}
inline void SendMsgToGroup::_internal_set_group_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  group_id_ = value;
}
inline void SendMsgToGroup::set_group_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_group_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.SendMsgToGroup.group_id)
}

// string msg = 3;
inline void SendMsgToGroup::clear_msg() {
  msg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SendMsgToGroup::msg() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.SendMsgToGroup.msg)
  return _internal_msg();
}
inline void SendMsgToGroup::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.SendMsgToGroup.msg)
}
inline std::string* SendMsgToGroup::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.SendMsgToGroup.msg)
  return _internal_mutable_msg();
}
inline const std::string& SendMsgToGroup::_internal_msg() const {
  return msg_.Get();
}
inline void SendMsgToGroup::_internal_set_msg(const std::string& value) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SendMsgToGroup::set_msg(std::string&& value) {
  
  msg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.SendMsgToGroup.msg)
}
inline void SendMsgToGroup::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.SendMsgToGroup.msg)
}
inline void SendMsgToGroup::set_msg(const char* value,
    size_t size) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.SendMsgToGroup.msg)
}
inline std::string* SendMsgToGroup::_internal_mutable_msg() {
  
  return msg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SendMsgToGroup::release_msg() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.SendMsgToGroup.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SendMsgToGroup::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.SendMsgToGroup.msg)
}
inline std::string* SendMsgToGroup::unsafe_arena_release_msg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.SendMsgToGroup.msg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return msg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void SendMsgToGroup::unsafe_arena_set_allocated_msg(
    std::string* msg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      msg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.SendMsgToGroup.msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msgpb_2fsend_5fmsg_5fto_5fgroup_2eproto
