// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: group_messages.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_group_5fmessages_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_group_5fmessages_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_group_5fmessages_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_group_5fmessages_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_group_5fmessages_2eproto;
namespace chatroom {
namespace datapb {
class GroupMessages;
class GroupMessagesDefaultTypeInternal;
extern GroupMessagesDefaultTypeInternal _GroupMessages_default_instance_;
class SingleGroupMessage;
class SingleGroupMessageDefaultTypeInternal;
extern SingleGroupMessageDefaultTypeInternal _SingleGroupMessage_default_instance_;
}  // namespace datapb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::datapb::GroupMessages* Arena::CreateMaybeMessage<::chatroom::datapb::GroupMessages>(Arena*);
template<> ::chatroom::datapb::SingleGroupMessage* Arena::CreateMaybeMessage<::chatroom::datapb::SingleGroupMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace datapb {

// ===================================================================

class SingleGroupMessage PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.datapb.SingleGroupMessage) */ {
 public:
  inline SingleGroupMessage() : SingleGroupMessage(nullptr) {};
  virtual ~SingleGroupMessage();

  SingleGroupMessage(const SingleGroupMessage& from);
  SingleGroupMessage(SingleGroupMessage&& from) noexcept
    : SingleGroupMessage() {
    *this = ::std::move(from);
  }

  inline SingleGroupMessage& operator=(const SingleGroupMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline SingleGroupMessage& operator=(SingleGroupMessage&& from) noexcept {
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
  static const SingleGroupMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const SingleGroupMessage* internal_default_instance() {
    return reinterpret_cast<const SingleGroupMessage*>(
               &_SingleGroupMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(SingleGroupMessage& a, SingleGroupMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(SingleGroupMessage* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(SingleGroupMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline SingleGroupMessage* New() const final {
    return CreateMaybeMessage<SingleGroupMessage>(nullptr);
  }

  SingleGroupMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<SingleGroupMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const SingleGroupMessage& from);
  void MergeFrom(const SingleGroupMessage& from);
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
  void InternalSwap(SingleGroupMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.datapb.SingleGroupMessage";
  }
  protected:
  explicit SingleGroupMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_group_5fmessages_2eproto);
    return ::descriptor_table_group_5fmessages_2eproto.file_level_metadata[kIndexInFileMessages];
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

  // @@protoc_insertion_point(class_scope:chatroom.datapb.SingleGroupMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_group_5fmessages_2eproto;
};
// -------------------------------------------------------------------

class GroupMessages PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.datapb.GroupMessages) */ {
 public:
  inline GroupMessages() : GroupMessages(nullptr) {};
  virtual ~GroupMessages();

  GroupMessages(const GroupMessages& from);
  GroupMessages(GroupMessages&& from) noexcept
    : GroupMessages() {
    *this = ::std::move(from);
  }

  inline GroupMessages& operator=(const GroupMessages& from) {
    CopyFrom(from);
    return *this;
  }
  inline GroupMessages& operator=(GroupMessages&& from) noexcept {
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
  static const GroupMessages& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GroupMessages* internal_default_instance() {
    return reinterpret_cast<const GroupMessages*>(
               &_GroupMessages_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GroupMessages& a, GroupMessages& b) {
    a.Swap(&b);
  }
  inline void Swap(GroupMessages* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GroupMessages* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GroupMessages* New() const final {
    return CreateMaybeMessage<GroupMessages>(nullptr);
  }

  GroupMessages* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GroupMessages>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GroupMessages& from);
  void MergeFrom(const GroupMessages& from);
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
  void InternalSwap(GroupMessages* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.datapb.GroupMessages";
  }
  protected:
  explicit GroupMessages(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_group_5fmessages_2eproto);
    return ::descriptor_table_group_5fmessages_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgsFieldNumber = 1,
  };
  // repeated .chatroom.datapb.SingleGroupMessage msgs = 1;
  int msgs_size() const;
  private:
  int _internal_msgs_size() const;
  public:
  void clear_msgs();
  ::chatroom::datapb::SingleGroupMessage* mutable_msgs(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::SingleGroupMessage >*
      mutable_msgs();
  private:
  const ::chatroom::datapb::SingleGroupMessage& _internal_msgs(int index) const;
  ::chatroom::datapb::SingleGroupMessage* _internal_add_msgs();
  public:
  const ::chatroom::datapb::SingleGroupMessage& msgs(int index) const;
  ::chatroom::datapb::SingleGroupMessage* add_msgs();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::SingleGroupMessage >&
      msgs() const;

  // @@protoc_insertion_point(class_scope:chatroom.datapb.GroupMessages)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::SingleGroupMessage > msgs_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_group_5fmessages_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SingleGroupMessage

// uint32 user_id = 1;
inline void SingleGroupMessage::clear_user_id() {
  user_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SingleGroupMessage::_internal_user_id() const {
  return user_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 SingleGroupMessage::user_id() const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.SingleGroupMessage.user_id)
  return _internal_user_id();
}
inline void SingleGroupMessage::_internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  user_id_ = value;
}
inline void SingleGroupMessage::set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:chatroom.datapb.SingleGroupMessage.user_id)
}

// string msg = 2;
inline void SingleGroupMessage::clear_msg() {
  msg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& SingleGroupMessage::msg() const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.SingleGroupMessage.msg)
  return _internal_msg();
}
inline void SingleGroupMessage::set_msg(const std::string& value) {
  _internal_set_msg(value);
  // @@protoc_insertion_point(field_set:chatroom.datapb.SingleGroupMessage.msg)
}
inline std::string* SingleGroupMessage::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:chatroom.datapb.SingleGroupMessage.msg)
  return _internal_mutable_msg();
}
inline const std::string& SingleGroupMessage::_internal_msg() const {
  return msg_.Get();
}
inline void SingleGroupMessage::_internal_set_msg(const std::string& value) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void SingleGroupMessage::set_msg(std::string&& value) {
  
  msg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.datapb.SingleGroupMessage.msg)
}
inline void SingleGroupMessage::set_msg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.datapb.SingleGroupMessage.msg)
}
inline void SingleGroupMessage::set_msg(const char* value,
    size_t size) {
  
  msg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.datapb.SingleGroupMessage.msg)
}
inline std::string* SingleGroupMessage::_internal_mutable_msg() {
  
  return msg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* SingleGroupMessage::release_msg() {
  // @@protoc_insertion_point(field_release:chatroom.datapb.SingleGroupMessage.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void SingleGroupMessage::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.datapb.SingleGroupMessage.msg)
}
inline std::string* SingleGroupMessage::unsafe_arena_release_msg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.datapb.SingleGroupMessage.msg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return msg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void SingleGroupMessage::unsafe_arena_set_allocated_msg(
    std::string* msg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      msg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.datapb.SingleGroupMessage.msg)
}

// -------------------------------------------------------------------

// GroupMessages

// repeated .chatroom.datapb.SingleGroupMessage msgs = 1;
inline int GroupMessages::_internal_msgs_size() const {
  return msgs_.size();
}
inline int GroupMessages::msgs_size() const {
  return _internal_msgs_size();
}
inline void GroupMessages::clear_msgs() {
  msgs_.Clear();
}
inline ::chatroom::datapb::SingleGroupMessage* GroupMessages::mutable_msgs(int index) {
  // @@protoc_insertion_point(field_mutable:chatroom.datapb.GroupMessages.msgs)
  return msgs_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::SingleGroupMessage >*
GroupMessages::mutable_msgs() {
  // @@protoc_insertion_point(field_mutable_list:chatroom.datapb.GroupMessages.msgs)
  return &msgs_;
}
inline const ::chatroom::datapb::SingleGroupMessage& GroupMessages::_internal_msgs(int index) const {
  return msgs_.Get(index);
}
inline const ::chatroom::datapb::SingleGroupMessage& GroupMessages::msgs(int index) const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.GroupMessages.msgs)
  return _internal_msgs(index);
}
inline ::chatroom::datapb::SingleGroupMessage* GroupMessages::_internal_add_msgs() {
  return msgs_.Add();
}
inline ::chatroom::datapb::SingleGroupMessage* GroupMessages::add_msgs() {
  // @@protoc_insertion_point(field_add:chatroom.datapb.GroupMessages.msgs)
  return _internal_add_msgs();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::SingleGroupMessage >&
GroupMessages::msgs() const {
  // @@protoc_insertion_point(field_list:chatroom.datapb.GroupMessages.msgs)
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
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_group_5fmessages_2eproto
