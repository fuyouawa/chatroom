// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgpb/get_msgs_from_group_ack.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto

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
#include "datapb/group_message.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class GetMsgsFromGroupAck;
class GetMsgsFromGroupAckDefaultTypeInternal;
extern GetMsgsFromGroupAckDefaultTypeInternal _GetMsgsFromGroupAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::GetMsgsFromGroupAck* Arena::CreateMaybeMessage<::chatroom::msgpb::GetMsgsFromGroupAck>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class GetMsgsFromGroupAck PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.GetMsgsFromGroupAck) */ {
 public:
  inline GetMsgsFromGroupAck() : GetMsgsFromGroupAck(nullptr) {};
  virtual ~GetMsgsFromGroupAck();

  GetMsgsFromGroupAck(const GetMsgsFromGroupAck& from);
  GetMsgsFromGroupAck(GetMsgsFromGroupAck&& from) noexcept
    : GetMsgsFromGroupAck() {
    *this = ::std::move(from);
  }

  inline GetMsgsFromGroupAck& operator=(const GetMsgsFromGroupAck& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetMsgsFromGroupAck& operator=(GetMsgsFromGroupAck&& from) noexcept {
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
  static const GetMsgsFromGroupAck& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetMsgsFromGroupAck* internal_default_instance() {
    return reinterpret_cast<const GetMsgsFromGroupAck*>(
               &_GetMsgsFromGroupAck_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetMsgsFromGroupAck& a, GetMsgsFromGroupAck& b) {
    a.Swap(&b);
  }
  inline void Swap(GetMsgsFromGroupAck* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetMsgsFromGroupAck* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetMsgsFromGroupAck* New() const final {
    return CreateMaybeMessage<GetMsgsFromGroupAck>(nullptr);
  }

  GetMsgsFromGroupAck* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetMsgsFromGroupAck>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetMsgsFromGroupAck& from);
  void MergeFrom(const GetMsgsFromGroupAck& from);
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
  void InternalSwap(GetMsgsFromGroupAck* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.GetMsgsFromGroupAck";
  }
  protected:
  explicit GetMsgsFromGroupAck(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto);
    return ::descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgsFieldNumber = 3,
    kErrmsgFieldNumber = 2,
    kSuccessFieldNumber = 1,
  };
  // repeated .chatroom.datapb.GroupMessage msgs = 3;
  int msgs_size() const;
  private:
  int _internal_msgs_size() const;
  public:
  void clear_msgs();
  ::chatroom::datapb::GroupMessage* mutable_msgs(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessage >*
      mutable_msgs();
  private:
  const ::chatroom::datapb::GroupMessage& _internal_msgs(int index) const;
  ::chatroom::datapb::GroupMessage* _internal_add_msgs();
  public:
  const ::chatroom::datapb::GroupMessage& msgs(int index) const;
  ::chatroom::datapb::GroupMessage* add_msgs();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessage >&
      msgs() const;

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

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.GetMsgsFromGroupAck)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessage > msgs_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetMsgsFromGroupAck

// bool success = 1;
inline void GetMsgsFromGroupAck::clear_success() {
  success_ = false;
}
inline bool GetMsgsFromGroupAck::_internal_success() const {
  return success_;
}
inline bool GetMsgsFromGroupAck::success() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetMsgsFromGroupAck.success)
  return _internal_success();
}
inline void GetMsgsFromGroupAck::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void GetMsgsFromGroupAck::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetMsgsFromGroupAck.success)
}

// string errmsg = 2;
inline void GetMsgsFromGroupAck::clear_errmsg() {
  errmsg_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& GetMsgsFromGroupAck::errmsg() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
  return _internal_errmsg();
}
inline void GetMsgsFromGroupAck::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}
inline std::string* GetMsgsFromGroupAck::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& GetMsgsFromGroupAck::_internal_errmsg() const {
  return errmsg_.Get();
}
inline void GetMsgsFromGroupAck::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void GetMsgsFromGroupAck::set_errmsg(std::string&& value) {
  
  errmsg_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}
inline void GetMsgsFromGroupAck::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}
inline void GetMsgsFromGroupAck::set_errmsg(const char* value,
    size_t size) {
  
  errmsg_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}
inline std::string* GetMsgsFromGroupAck::_internal_mutable_errmsg() {
  
  return errmsg_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* GetMsgsFromGroupAck::release_errmsg() {
  // @@protoc_insertion_point(field_release:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
  return errmsg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void GetMsgsFromGroupAck::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}
inline std::string* GetMsgsFromGroupAck::unsafe_arena_release_errmsg() {
  // @@protoc_insertion_point(field_unsafe_arena_release:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return errmsg_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void GetMsgsFromGroupAck::unsafe_arena_set_allocated_errmsg(
    std::string* errmsg) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      errmsg, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:chatroom.msgpb.GetMsgsFromGroupAck.errmsg)
}

// repeated .chatroom.datapb.GroupMessage msgs = 3;
inline int GetMsgsFromGroupAck::_internal_msgs_size() const {
  return msgs_.size();
}
inline int GetMsgsFromGroupAck::msgs_size() const {
  return _internal_msgs_size();
}
inline ::chatroom::datapb::GroupMessage* GetMsgsFromGroupAck::mutable_msgs(int index) {
  // @@protoc_insertion_point(field_mutable:chatroom.msgpb.GetMsgsFromGroupAck.msgs)
  return msgs_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessage >*
GetMsgsFromGroupAck::mutable_msgs() {
  // @@protoc_insertion_point(field_mutable_list:chatroom.msgpb.GetMsgsFromGroupAck.msgs)
  return &msgs_;
}
inline const ::chatroom::datapb::GroupMessage& GetMsgsFromGroupAck::_internal_msgs(int index) const {
  return msgs_.Get(index);
}
inline const ::chatroom::datapb::GroupMessage& GetMsgsFromGroupAck::msgs(int index) const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetMsgsFromGroupAck.msgs)
  return _internal_msgs(index);
}
inline ::chatroom::datapb::GroupMessage* GetMsgsFromGroupAck::_internal_add_msgs() {
  return msgs_.Add();
}
inline ::chatroom::datapb::GroupMessage* GetMsgsFromGroupAck::add_msgs() {
  // @@protoc_insertion_point(field_add:chatroom.msgpb.GetMsgsFromGroupAck.msgs)
  return _internal_add_msgs();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::chatroom::datapb::GroupMessage >&
GetMsgsFromGroupAck::msgs() const {
  // @@protoc_insertion_point(field_list:chatroom.msgpb.GetMsgsFromGroupAck.msgs)
  return msgs_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5fgroup_5fack_2eproto