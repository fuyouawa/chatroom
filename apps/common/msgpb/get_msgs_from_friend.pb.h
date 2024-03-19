// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msgpb/get_msgs_from_friend.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto;
namespace chatroom {
namespace msgpb {
class GetMsgsFromFriend;
class GetMsgsFromFriendDefaultTypeInternal;
extern GetMsgsFromFriendDefaultTypeInternal _GetMsgsFromFriend_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::msgpb::GetMsgsFromFriend* Arena::CreateMaybeMessage<::chatroom::msgpb::GetMsgsFromFriend>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace msgpb {

// ===================================================================

class GetMsgsFromFriend PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.msgpb.GetMsgsFromFriend) */ {
 public:
  inline GetMsgsFromFriend() : GetMsgsFromFriend(nullptr) {};
  virtual ~GetMsgsFromFriend();

  GetMsgsFromFriend(const GetMsgsFromFriend& from);
  GetMsgsFromFriend(GetMsgsFromFriend&& from) noexcept
    : GetMsgsFromFriend() {
    *this = ::std::move(from);
  }

  inline GetMsgsFromFriend& operator=(const GetMsgsFromFriend& from) {
    CopyFrom(from);
    return *this;
  }
  inline GetMsgsFromFriend& operator=(GetMsgsFromFriend&& from) noexcept {
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
  static const GetMsgsFromFriend& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const GetMsgsFromFriend* internal_default_instance() {
    return reinterpret_cast<const GetMsgsFromFriend*>(
               &_GetMsgsFromFriend_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(GetMsgsFromFriend& a, GetMsgsFromFriend& b) {
    a.Swap(&b);
  }
  inline void Swap(GetMsgsFromFriend* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(GetMsgsFromFriend* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline GetMsgsFromFriend* New() const final {
    return CreateMaybeMessage<GetMsgsFromFriend>(nullptr);
  }

  GetMsgsFromFriend* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<GetMsgsFromFriend>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const GetMsgsFromFriend& from);
  void MergeFrom(const GetMsgsFromFriend& from);
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
  void InternalSwap(GetMsgsFromFriend* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.msgpb.GetMsgsFromFriend";
  }
  protected:
  explicit GetMsgsFromFriend(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto);
    return ::descriptor_table_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserIdFieldNumber = 1,
    kFriendIdFieldNumber = 2,
  };
  // uint32 user_id = 1;
  void clear_user_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id() const;
  void set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_user_id() const;
  void _internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 friend_id = 2;
  void clear_friend_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 friend_id() const;
  void set_friend_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_friend_id() const;
  void _internal_set_friend_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:chatroom.msgpb.GetMsgsFromFriend)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint32 user_id_;
  ::PROTOBUF_NAMESPACE_ID::uint32 friend_id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// GetMsgsFromFriend

// uint32 user_id = 1;
inline void GetMsgsFromFriend::clear_user_id() {
  user_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GetMsgsFromFriend::_internal_user_id() const {
  return user_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GetMsgsFromFriend::user_id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetMsgsFromFriend.user_id)
  return _internal_user_id();
}
inline void GetMsgsFromFriend::_internal_set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  user_id_ = value;
}
inline void GetMsgsFromFriend::set_user_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetMsgsFromFriend.user_id)
}

// uint32 friend_id = 2;
inline void GetMsgsFromFriend::clear_friend_id() {
  friend_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GetMsgsFromFriend::_internal_friend_id() const {
  return friend_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 GetMsgsFromFriend::friend_id() const {
  // @@protoc_insertion_point(field_get:chatroom.msgpb.GetMsgsFromFriend.friend_id)
  return _internal_friend_id();
}
inline void GetMsgsFromFriend::_internal_set_friend_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  friend_id_ = value;
}
inline void GetMsgsFromFriend::set_friend_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_friend_id(value);
  // @@protoc_insertion_point(field_set:chatroom.msgpb.GetMsgsFromFriend.friend_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msgpb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_msgpb_2fget_5fmsgs_5ffrom_5ffriend_2eproto
