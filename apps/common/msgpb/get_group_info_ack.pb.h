// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: get_group_info_ack.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_get_5fgroup_5finfo_5fack_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_get_5fgroup_5finfo_5fack_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_get_5fgroup_5finfo_5fack_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_get_5fgroup_5finfo_5fack_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_get_5fgroup_5finfo_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class GetGroupInfoAck;
class GetGroupInfoAckDefaultTypeInternal;
extern GetGroupInfoAckDefaultTypeInternal _GetGroupInfoAck_default_instance_;
class GroupMember;
class GroupMemberDefaultTypeInternal;
extern GroupMemberDefaultTypeInternal _GroupMember_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::GetGroupInfoAck* Arena::CreateMaybeMessage<::chatroom::msgpb::GetGroupInfoAck>(Arena*);
template<> ::chatroom::msgpb::GroupMember* Arena::CreateMaybeMessage<::chatroom::msgpb::GroupMember>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class GroupMember PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.GroupMember) */ {
 public:
  inline GroupMember() : GroupMember(nullptr) {};
  virtual ~GroupMember();

  GroupMember(const GroupMember& from);
  GroupMember(GroupMember&& from) noexcept
    : GroupMember() {
    *this = ::std::move(from);
  }

  inline GroupMember& operator=(const GroupMember& from) {
    CopyFrom(from);
    return *this;
  }
  inline GroupMember& operator=(GroupMember&& from) noexcept {
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
  static const GroupMember& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GroupMember* internal_default_instance() {
    return reinterpret_cast<const GroupMember*>(
               &_GroupMember_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GroupMember& a, GroupMember& b) {
    a.Swap(&b);
  }
  inline void Swap(GroupMember* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GroupMember* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GroupMember* New() const final {
    return CreateMaybeMessage<GroupMember>(nullptr);
  }

  GroupMember* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GroupMember>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GroupMember& from);
  void MergeFrom(const GroupMember& from);
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
  void InternalSwap(GroupMember* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.GroupMember";
  }
  protected:
  explicit GroupMember(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_get_5fgroup_5finfo_5fack_2eproto);
    return ::descriptor_table_get_5fgroup_5finfo_5fack_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kIdFieldNumber = 2,
    kPrivilegeFieldNumber = 3,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_name(
      std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // uint32 id = 2;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // int32 privilege = 3;
  void clear_privilege();
  ::PROTOBUF_NAMESPACE_ID::int32 privilege() const;
  void set_privilege(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_privilege() const;
  void _internal_set_privilege(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.GroupMember)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  ::PROTOBUF_NAMESPACE_ID::int32 privilege_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_get_5fgroup_5finfo_5fack_2eproto;
};
// -------------------------------------------------------------------

class GetGroupInfoAck PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.GetGroupInfoAck) */ {
 public:
  inline GetGroupInfoAck() : GetGroupInfoAck(nullptr) {};
  virtual ~GetGroupInfoAck();

  GetGroupInfoAck(const GetGroupInfoAck& from);
  GetGroupInfoAck(GetGroupInfoAck&& from) noexcept
    : GetGroupInfoAck() {
    *this = ::std::move(from);
  }

  inline GetGroupInfoAck& operator=(const GetGroupInfoAck& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetGroupInfoAck& operator=(GetGroupInfoAck&& from) noexcept {
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
  static const GetGroupInfoAck& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetGroupInfoAck* internal_default_instance() {
    return reinterpret_cast<const GetGroupInfoAck*>(
               &_GetGroupInfoAck_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(GetGroupInfoAck& a, GetGroupInfoAck& b) {
    a.Swap(&b);
  }
  inline void Swap(GetGroupInfoAck* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetGroupInfoAck* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetGroupInfoAck* New() const final {
    return CreateMaybeMessage<GetGroupInfoAck>(nullptr);
  }

  GetGroupInfoAck* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetGroupInfoAck>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetGroupInfoAck& from);
  void MergeFrom(const GetGroupInfoAck& from);
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
  void InternalSwap(GetGroupInfoAck* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.GetGroupInfoAck";
  }
  protected:
  explicit GetGroupInfoAck(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_get_5fgroup_5finfo_5fack_2eproto);
    return ::descriptor_table_get_5fgroup_5finfo_5fack_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMembersInfoFieldNumber = 4,
    kErrmsgFieldNumber = 2,
    kGroupNameFieldNumber = 3,
    kSuccessFieldNumber = 1,
  };
  // repeated .chatroom.msgpb.GroupMember members_info = 4;
  int members_info_size() const;
  private:
  int _internal_members_info_size() const;
  public:
  void clear_members_info();
  ::chatroom::msgpb::GroupMember* mutable_members_info(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::msgpb::GroupMember >*
      mutable_members_info();
  private:
  const ::chatroom::msgpb::GroupMember& _internal_members_info(int index) const;
  ::chatroom::msgpb::GroupMember* _internal_add_members_info();
  public:
  const ::chatroom::msgpb::GroupMember& members_info(int index) const;
  ::chatroom::msgpb::GroupMember* add_members_info();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::msgpb::GroupMember >&
      members_info() const;

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

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.GetGroupInfoAck)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::msgpb::GroupMember > members_info_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr group_name_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_get_5fgroup_5finfo_5fack_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GroupMember

// string name = 1;
inline void GroupMember::clear_name() {
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GroupMember::name() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GroupMember.name)
  return _internal_name();
}
inline void GroupMember::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GroupMember.name)
}
inline std::string* GroupMember::mutable_name() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GroupMember.name)
  return _internal_mutable_name();
}
inline const std::string& GroupMember::_internal_name() const {
  return name_.Get();
}
inline void GroupMember::_internal_set_name(const std::string& value) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GroupMember::set_name(std::string&& value) {
  
  name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.GroupMember.name)
}
inline void GroupMember::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.GroupMember.name)
}
inline void GroupMember::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.GroupMember.name)
}
inline std::string* GroupMember::_internal_mutable_name() {
  
  return name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GroupMember::release_name() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.GroupMember.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GroupMember::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.GroupMember.name)
}
inline std::string* GroupMember::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.GroupMember.name)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GroupMember::unsafe_arena_set_allocated_name(
    std::string* name) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (name != nullptr) {
    
  } else {
    
  }
  name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      name, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.GroupMember.name)
}

// uint32 id = 2;
inline void GroupMember::clear_id() {
  id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GroupMember::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GroupMember::id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GroupMember.id)
  return _internal_id();
}
inline void GroupMember::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  id_ = value;
}
inline void GroupMember::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GroupMember.id)
}

// int32 privilege = 3;
inline void GroupMember::clear_privilege() {
  privilege_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupMember::_internal_privilege() const {
  return privilege_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 GroupMember::privilege() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GroupMember.privilege)
  return _internal_privilege();
}
inline void GroupMember::_internal_set_privilege(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  privilege_ = value;
}
inline void GroupMember::set_privilege(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_privilege(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GroupMember.privilege)
}

// -------------------------------------------------------------------

// GetGroupInfoAck

// bool success = 1;
inline void GetGroupInfoAck::clear_success() {
  success_ = false;
}
inline bool GetGroupInfoAck::_internal_success() const {
  return success_;
}
inline bool GetGroupInfoAck::success() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetGroupInfoAck.success)
  return _internal_success();
}
inline void GetGroupInfoAck::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void GetGroupInfoAck::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetGroupInfoAck.success)
}

// string errmsg = 2;
inline void GetGroupInfoAck::clear_errmsg() {
  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GetGroupInfoAck::errmsg() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetGroupInfoAck.errmsg)
  return _internal_errmsg();
}
inline void GetGroupInfoAck::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetGroupInfoAck.errmsg)
}
inline std::string* GetGroupInfoAck::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GetGroupInfoAck.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& GetGroupInfoAck::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void GetGroupInfoAck::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GetGroupInfoAck::set_errmsg(std::string&& value) {
  
  errmsg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.GetGroupInfoAck.errmsg)
}
inline void GetGroupInfoAck::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.GetGroupInfoAck.errmsg)
}
inline void GetGroupInfoAck::set_errmsg(const char* value,
    size_t size) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.GetGroupInfoAck.errmsg)
}
inline std::string* GetGroupInfoAck::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GetGroupInfoAck::release_errmsg() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.GetGroupInfoAck.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GetGroupInfoAck::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.GetGroupInfoAck.errmsg)
}
inline std::string* GetGroupInfoAck::unsafe_arena_release_errmsg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.GetGroupInfoAck.errmsg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return errmsg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GetGroupInfoAck::unsafe_arena_set_allocated_errmsg(
    std::string* errmsg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      errmsg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.GetGroupInfoAck.errmsg)
}

// string group_name = 3;
inline void GetGroupInfoAck::clear_group_name() {
  group_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GetGroupInfoAck::group_name() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetGroupInfoAck.group_name)
  return _internal_group_name();
}
inline void GetGroupInfoAck::set_group_name(const std::string& value) {
  _internal_set_group_name(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetGroupInfoAck.group_name)
}
inline std::string* GetGroupInfoAck::mutable_group_name() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GetGroupInfoAck.group_name)
  return _internal_mutable_group_name();
}
inline const std::string& GetGroupInfoAck::_internal_group_name() const {
  return group_name_.Get();
}
inline void GetGroupInfoAck::_internal_set_group_name(const std::string& value) {
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GetGroupInfoAck::set_group_name(std::string&& value) {
  
  group_name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.GetGroupInfoAck.group_name)
}
inline void GetGroupInfoAck::set_group_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.GetGroupInfoAck.group_name)
}
inline void GetGroupInfoAck::set_group_name(const char* value,
    size_t size) {
  
  group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.GetGroupInfoAck.group_name)
}
inline std::string* GetGroupInfoAck::_internal_mutable_group_name() {
  
  return group_name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GetGroupInfoAck::release_group_name() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.GetGroupInfoAck.group_name)
  return group_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GetGroupInfoAck::set_allocated_group_name(std::string* group_name) {
  if (group_name != nullptr) {
    
  } else {
    
  }
  group_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), group_name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.GetGroupInfoAck.group_name)
}
inline std::string* GetGroupInfoAck::unsafe_arena_release_group_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.GetGroupInfoAck.group_name)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return group_name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GetGroupInfoAck::unsafe_arena_set_allocated_group_name(
    std::string* group_name) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (group_name != nullptr) {
    
  } else {
    
  }
  group_name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      group_name, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.GetGroupInfoAck.group_name)
}

// repeated .chatroom.msgpb.GroupMember members_info = 4;
inline int GetGroupInfoAck::_internal_members_info_size() const {
  return members_info_.size();
}
inline int GetGroupInfoAck::members_info_size() const {
  return _internal_members_info_size();
}
inline void GetGroupInfoAck::clear_members_info() {
  members_info_.Clear();
}
inline ::chatroom::msgpb::GroupMember* GetGroupInfoAck::mutable_members_info(int index) {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GetGroupInfoAck.members_info)
  return members_info_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::msgpb::GroupMember >*
GetGroupInfoAck::mutable_members_info() {
  // @@protoc_insertion_point(field_mutable_list:chatroom.msgpb.GetGroupInfoAck.members_info)
  return &members_info_;
}
inline const ::chatroom::msgpb::GroupMember& GetGroupInfoAck::_internal_members_info(int index) const {
  return members_info_.Get(index);
}
inline const ::chatroom::msgpb::GroupMember& GetGroupInfoAck::members_info(int index) const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetGroupInfoAck.members_info)
  return _internal_members_info(index);
}
inline ::chatroom::msgpb::GroupMember* GetGroupInfoAck::_internal_add_members_info() {
  return members_info_.Add();
}
inline ::chatroom::msgpb::GroupMember* GetGroupInfoAck::add_members_info() {
  // @@protoc_insertion_point(field_add:chatroom.msgpb.GetGroupInfoAck.members_info)
  return _internal_add_members_info();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::msgpb::GroupMember >&
GetGroupInfoAck::members_info() const {
  // @@protoc_insertion_point(field_list:chatroom.msgpb.GetGroupInfoAck.members_info)
  return members_info_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_get_5fgroup_5finfo_5fack_2eproto
