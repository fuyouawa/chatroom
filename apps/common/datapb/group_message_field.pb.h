// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datapb/group_message_field.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_datapb_2fgroup_5fmessage_5ffield_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_datapb_2fgroup_5fmessage_5ffield_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_datapb_2fgroup_5fmessage_5ffield_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_datapb_2fgroup_5fmessage_5ffield_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_datapb_2fgroup_5fmessage_5ffield_2eproto;
namespace chatroom {
namespace datapb {
class GroupMessageField;
class GroupMessageFieldDefaultTypeInternal;
extern GroupMessageFieldDefaultTypeInternal _GroupMessageField_default_instance_;
class GroupMessageField_Message;
class GroupMessageField_MessageDefaultTypeInternal;
extern GroupMessageField_MessageDefaultTypeInternal _GroupMessageField_Message_default_instance_;
}  // namespace datapb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::datapb::GroupMessageField* Arena::CreateMaybeMessage<::chatroom::datapb::GroupMessageField>(Arena*);
template<> ::chatroom::datapb::GroupMessageField_Message* Arena::CreateMaybeMessage<::chatroom::datapb::GroupMessageField_Message>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace datapb {

// ===================================================================

class GroupMessageField_Message PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.datapb.GroupMessageField.Message) */ {
 public:
  inline GroupMessageField_Message() : GroupMessageField_Message(nullptr) {};
  virtual ~GroupMessageField_Message();

  GroupMessageField_Message(const GroupMessageField_Message& from);
  GroupMessageField_Message(GroupMessageField_Message&& from) noexcept
    : GroupMessageField_Message() {
    *this = ::std::move(from);
  }

  inline GroupMessageField_Message& operator=(const GroupMessageField_Message& from) {
    CopyFrom(from);
    return *this;
  }
  inline GroupMessageField_Message& operator=(GroupMessageField_Message&& from) noexcept {
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
  static const GroupMessageField_Message& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GroupMessageField_Message* internal_default_instance() {
    return reinterpret_cast<const GroupMessageField_Message*>(
               &_GroupMessageField_Message_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GroupMessageField_Message& a, GroupMessageField_Message& b) {
    a.Swap(&b);
  }
  inline void Swap(GroupMessageField_Message* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GroupMessageField_Message* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GroupMessageField_Message* New() const final {
    return CreateMaybeMessage<GroupMessageField_Message>(nullptr);
  }

  GroupMessageField_Message* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GroupMessageField_Message>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GroupMessageField_Message& from);
  void MergeFrom(const GroupMessageField_Message& from);
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
  void InternalSwap(GroupMessageField_Message* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.datapb.GroupMessageField.Message";
  }
  protected:
  explicit GroupMessageField_Message(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_datapb_2fgroup_5fmessage_5ffield_2eproto);
    return ::descriptor_table_datapb_2fgroup_5fmessage_5ffield_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 2,
    kUserIdFieldNumber = 1,
  };
  // string msg = 2;
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

  // @@protoc_insertion_point(class_scope:chatroom.datapb.GroupMessageField.Message)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_datapb_2fgroup_5fmessage_5ffield_2eproto;
};
// -------------------------------------------------------------------

class GroupMessageField PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.datapb.GroupMessageField) */ {
 public:
  inline GroupMessageField() : GroupMessageField(nullptr) {};
  virtual ~GroupMessageField();

  GroupMessageField(const GroupMessageField& from);
  GroupMessageField(GroupMessageField&& from) noexcept
    : GroupMessageField() {
    *this = ::std::move(from);
  }

  inline GroupMessageField& operator=(const GroupMessageField& from) {
    CopyFrom(from);
    return *this;
  }
  inline GroupMessageField& operator=(GroupMessageField&& from) noexcept {
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
  static const GroupMessageField& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GroupMessageField* internal_default_instance() {
    return reinterpret_cast<const GroupMessageField*>(
               &_GroupMessageField_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GroupMessageField& a, GroupMessageField& b) {
    a.Swap(&b);
  }
  inline void Swap(GroupMessageField* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GroupMessageField* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GroupMessageField* New() const final {
    return CreateMaybeMessage<GroupMessageField>(nullptr);
  }

  GroupMessageField* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GroupMessageField>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GroupMessageField& from);
  void MergeFrom(const GroupMessageField& from);
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
  void InternalSwap(GroupMessageField* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.datapb.GroupMessageField";
  }
  protected:
  explicit GroupMessageField(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_datapb_2fgroup_5fmessage_5ffield_2eproto);
    return ::descriptor_table_datapb_2fgroup_5fmessage_5ffield_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef GroupMessageField_Message Message;

  // accessors -------------------------------------------------------

  enum : int {
    kMsgsFieldNumber = 1,
  };
  // repeated .chatroom.datapb.GroupMessageField.Message msgs = 1;
  int msgs_size() const;
  private:
  int _internal_msgs_size() const;
  public:
  void clear_msgs();
  ::chatroom::datapb::GroupMessageField_Message* mutable_msgs(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessageField_Message >*
      mutable_msgs();
  private:
  const ::chatroom::datapb::GroupMessageField_Message& _internal_msgs(int index) const;
  ::chatroom::datapb::GroupMessageField_Message* _internal_add_msgs();
  public:
  const ::chatroom::datapb::GroupMessageField_Message& msgs(int index) const;
  ::chatroom::datapb::GroupMessageField_Message* add_msgs();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessageField_Message >&
      msgs() const;

  // @@protoc_insertion_point(class_scope:chatroom.datapb.GroupMessageField)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessageField_Message > msgs_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_datapb_2fgroup_5fmessage_5ffield_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GroupMessageField_Message

// uint32 user_id = 1;
inline void GroupMessageField_Message::clear_user_id() {
  user_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GroupMessageField_Message::_internal_user_id() const {
  return user_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GroupMessageField_Message::user_id() const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.GroupMessageField.Message.user_id)
  return _internal_user_id();
}
inline void GroupMessageField_Message::_internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  user_id_ = value;
}
inline void GroupMessageField_Message::set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:chatroom.datapb.GroupMessageField.Message.user_id)
}

// string msg = 2;
inline void GroupMessageField_Message::clear_msg() {
  msg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GroupMessageField_Message::msg() const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.GroupMessageField.Message.msg)
  return _internal_msg();
}
inline void GroupMessageField_Message::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:chatroom.datapb.GroupMessageField.Message.msg)
}
inline std::string* GroupMessageField_Message::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:chatroom.datapb.GroupMessageField.Message.msg)
  return _internal_mutable_msg();
}
inline const std::string& GroupMessageField_Message::_internal_msg() const {
  return msg_.Get();
}
inline void GroupMessageField_Message::_internal_set_msg(const std::string& value) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GroupMessageField_Message::set_msg(std::string&& value) {
  
  msg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.datapb.GroupMessageField.Message.msg)
}
inline void GroupMessageField_Message::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.datapb.GroupMessageField.Message.msg)
}
inline void GroupMessageField_Message::set_msg(const char* value,
    size_t size) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.datapb.GroupMessageField.Message.msg)
}
inline std::string* GroupMessageField_Message::_internal_mutable_msg() {
  
  return msg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GroupMessageField_Message::release_msg() {
  // @@protoc_insertion_point(field_release:chatroom.datapb.GroupMessageField.Message.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GroupMessageField_Message::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.datapb.GroupMessageField.Message.msg)
}
inline std::string* GroupMessageField_Message::unsafe_arena_release_msg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.datapb.GroupMessageField.Message.msg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return msg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GroupMessageField_Message::unsafe_arena_set_allocated_msg(
    std::string* msg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      msg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.datapb.GroupMessageField.Message.msg)
}

// -------------------------------------------------------------------

// GroupMessageField

// repeated .chatroom.datapb.GroupMessageField.Message msgs = 1;
inline int GroupMessageField::_internal_msgs_size() const {
  return msgs_.size();
}
inline int GroupMessageField::msgs_size() const {
  return _internal_msgs_size();
}
inline void GroupMessageField::clear_msgs() {
  msgs_.Clear();
}
inline ::chatroom::datapb::GroupMessageField_Message* GroupMessageField::mutable_msgs(int index) {
  // @@protoc_insertion_point(field_mutable:chatroom.datapb.GroupMessageField.msgs)
  return msgs_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessageField_Message >*
GroupMessageField::mutable_msgs() {
  // @@protoc_insertion_point(field_mutable_list:chatroom.datapb.GroupMessageField.msgs)
  return &msgs_;
}
inline const ::chatroom::datapb::GroupMessageField_Message& GroupMessageField::_internal_msgs(int index) const {
  return msgs_.Get(index);
}
inline const ::chatroom::datapb::GroupMessageField_Message& GroupMessageField::msgs(int index) const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.GroupMessageField.msgs)
  return _internal_msgs(index);
}
inline ::chatroom::datapb::GroupMessageField_Message* GroupMessageField::_internal_add_msgs() {
  return msgs_.Add();
}
inline ::chatroom::datapb::GroupMessageField_Message* GroupMessageField::add_msgs() {
  // @@protoc_insertion_point(field_add:chatroom.datapb.GroupMessageField.msgs)
  return _internal_add_msgs();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessageField_Message >&
GroupMessageField::msgs() const {
  // @@protoc_insertion_point(field_list:chatroom.datapb.GroupMessageField.msgs)
  return msgs_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace datapb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_datapb_2fgroup_5fmessage_5ffield_2eproto