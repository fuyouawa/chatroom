// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: get_group_info_ack.proto

#include "get_group_info_ack.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_get_5fgroup_5finfo_5fack_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto;
namespace chatroom {
namespace msgpb {
class GroupMemberDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GroupMember> _instance;
} _GroupMember_default_instance_;
class GetGroupInfoAckDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<GetGroupInfoAck> _instance;
} _GetGroupInfoAck_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_GetGroupInfoAck_default_instance_;
    new (ptr) ::chatroom::msgpb::GetGroupInfoAck();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::GetGroupInfoAck::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto}, {
      &scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto.base,}};

static void InitDefaultsscc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_GroupMember_default_instance_;
    new (ptr) ::chatroom::msgpb::GroupMember();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::GroupMember::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_get_5fgroup_5finfo_5fack_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_get_5fgroup_5finfo_5fack_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_get_5fgroup_5finfo_5fack_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_get_5fgroup_5finfo_5fack_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupMember, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupMember, name_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupMember, id_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GroupMember, privilege_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetGroupInfoAck, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetGroupInfoAck, group_name_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::GetGroupInfoAck, members_info_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::GroupMember)},
  { 8, -1, sizeof(::chatroom::msgpb::GetGroupInfoAck)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_GroupMember_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_GetGroupInfoAck_default_instance_),
};

const char descriptor_table_protodef_get_5fgroup_5finfo_5fack_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\030get_group_info_ack.proto\022\016chatroom.msg"
  "pb\":\n\013GroupMember\022\014\n\004name\030\001 \001(\t\022\n\n\002id\030\002 "
  "\001(\r\022\021\n\tprivilege\030\003 \001(\005\"X\n\017GetGroupInfoAc"
  "k\022\022\n\ngroup_name\030\001 \001(\t\0221\n\014members_info\030\002 "
  "\003(\0132\033.chatroom.msgpb.GroupMemberb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_get_5fgroup_5finfo_5fack_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_get_5fgroup_5finfo_5fack_2eproto_sccs[2] = {
  &scc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto.base,
  &scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_get_5fgroup_5finfo_5fack_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_get_5fgroup_5finfo_5fack_2eproto = {
  false, false, descriptor_table_protodef_get_5fgroup_5finfo_5fack_2eproto, "get_group_info_ack.proto", 200,
  &descriptor_table_get_5fgroup_5finfo_5fack_2eproto_once, descriptor_table_get_5fgroup_5finfo_5fack_2eproto_sccs, descriptor_table_get_5fgroup_5finfo_5fack_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_get_5fgroup_5finfo_5fack_2eproto::offsets,
  file_level_metadata_get_5fgroup_5finfo_5fack_2eproto, 2, file_level_enum_descriptors_get_5fgroup_5finfo_5fack_2eproto, file_level_service_descriptors_get_5fgroup_5finfo_5fack_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_get_5fgroup_5finfo_5fack_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_get_5fgroup_5finfo_5fack_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void GroupMember::InitAsDefaultInstance() {
}
class GroupMember::_Internal {
 public:
};

GroupMember::GroupMember(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.GroupMember)
}
GroupMember::GroupMember(const GroupMember& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_name().empty()) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_name(),
      GetArena());
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&privilege_) -
    reinterpret_cast<char*>(&id_)) + sizeof(privilege_));
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.GroupMember)
}

void GroupMember::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto.base);
  name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&privilege_) -
      reinterpret_cast<char*>(&id_)) + sizeof(privilege_));
}

GroupMember::~GroupMember() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.GroupMember)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GroupMember::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GroupMember::ArenaDtor(void* object) {
  GroupMember* _this = reinterpret_cast< GroupMember* >(object);
  (void)_this;
}
void GroupMember::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GroupMember::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GroupMember& GroupMember::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GroupMember_get_5fgroup_5finfo_5fack_2eproto.base);
  return *internal_default_instance();
}


void GroupMember::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.GroupMember)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&privilege_) -
      reinterpret_cast<char*>(&id_)) + sizeof(privilege_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GroupMember::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.GroupMember.name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // uint32 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 privilege = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
          privilege_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GroupMember::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.GroupMember)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.GroupMember.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // uint32 id = 2;
  if (this->id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(2, this->_internal_id(), target);
  }

  // int32 privilege = 3;
  if (this->privilege() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_privilege(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.GroupMember)
  return target;
}

size_t GroupMember::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.GroupMember)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (this->name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // uint32 id = 2;
  if (this->id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_id());
  }

  // int32 privilege = 3;
  if (this->privilege() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_privilege());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GroupMember::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.GroupMember)
  GOOGLE_DCHECK_NE(&from, this);
  const GroupMember* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GroupMember>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.GroupMember)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.GroupMember)
    MergeFrom(*source);
  }
}

void GroupMember::MergeFrom(const GroupMember& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.GroupMember)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.name().size() > 0) {
    _internal_set_name(from._internal_name());
  }
  if (from.id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from.privilege() != 0) {
    _internal_set_privilege(from._internal_privilege());
  }
}

void GroupMember::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.GroupMember)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GroupMember::CopyFrom(const GroupMember& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.GroupMember)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GroupMember::IsInitialized() const {
  return true;
}

void GroupMember::InternalSwap(GroupMember* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  name_.Swap(&other->name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(GroupMember, privilege_)
      + sizeof(GroupMember::privilege_)
      - PROTOBUF_FIELD_OFFSET(GroupMember, id_)>(
          reinterpret_cast<char*>(&id_),
          reinterpret_cast<char*>(&other->id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata GroupMember::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void GetGroupInfoAck::InitAsDefaultInstance() {
}
class GetGroupInfoAck::_Internal {
 public:
};

GetGroupInfoAck::GetGroupInfoAck(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  members_info_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.GetGroupInfoAck)
}
GetGroupInfoAck::GetGroupInfoAck(const GetGroupInfoAck& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      members_info_(from.members_info_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  group_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_group_name().empty()) {
    group_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_group_name(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.GetGroupInfoAck)
}

void GetGroupInfoAck::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto.base);
  group_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

GetGroupInfoAck::~GetGroupInfoAck() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.GetGroupInfoAck)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void GetGroupInfoAck::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  group_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void GetGroupInfoAck::ArenaDtor(void* object) {
  GetGroupInfoAck* _this = reinterpret_cast< GetGroupInfoAck* >(object);
  (void)_this;
}
void GetGroupInfoAck::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void GetGroupInfoAck::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const GetGroupInfoAck& GetGroupInfoAck::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_GetGroupInfoAck_get_5fgroup_5finfo_5fack_2eproto.base);
  return *internal_default_instance();
}


void GetGroupInfoAck::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.GetGroupInfoAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  members_info_.Clear();
  group_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* GetGroupInfoAck::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string group_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_group_name();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "chatroom.msgpb.GetGroupInfoAck.group_name"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .chatroom.msgpb.GroupMember members_info = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_members_info(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* GetGroupInfoAck::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.GetGroupInfoAck)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string group_name = 1;
  if (this->group_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_group_name().data(), static_cast<int>(this->_internal_group_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "chatroom.msgpb.GetGroupInfoAck.group_name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_group_name(), target);
  }

  // repeated .chatroom.msgpb.GroupMember members_info = 2;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_members_info_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, this->_internal_members_info(i), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.GetGroupInfoAck)
  return target;
}

size_t GetGroupInfoAck::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.GetGroupInfoAck)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .chatroom.msgpb.GroupMember members_info = 2;
  total_size += 1UL * this->_internal_members_info_size();
  for (const auto& msg : this->members_info_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // string group_name = 1;
  if (this->group_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_group_name());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void GetGroupInfoAck::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.GetGroupInfoAck)
  GOOGLE_DCHECK_NE(&from, this);
  const GetGroupInfoAck* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<GetGroupInfoAck>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.GetGroupInfoAck)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.GetGroupInfoAck)
    MergeFrom(*source);
  }
}

void GetGroupInfoAck::MergeFrom(const GetGroupInfoAck& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.GetGroupInfoAck)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  members_info_.MergeFrom(from.members_info_);
  if (from.group_name().size() > 0) {
    _internal_set_group_name(from._internal_group_name());
  }
}

void GetGroupInfoAck::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.GetGroupInfoAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void GetGroupInfoAck::CopyFrom(const GetGroupInfoAck& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.GetGroupInfoAck)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool GetGroupInfoAck::IsInitialized() const {
  return true;
}

void GetGroupInfoAck::InternalSwap(GetGroupInfoAck* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  members_info_.InternalSwap(&other->members_info_);
  group_name_.Swap(&other->group_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata GetGroupInfoAck::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::GroupMember* Arena::CreateMaybeMessage< ::chatroom::msgpb::GroupMember >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::GroupMember >(arena);
}
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::GetGroupInfoAck* Arena::CreateMaybeMessage< ::chatroom::msgpb::GetGroupInfoAck >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::GetGroupInfoAck >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
