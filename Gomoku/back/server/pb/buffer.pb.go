// Code generated by protoc-gen-go. DO NOT EDIT.
// source: buffer.proto

package gomokuBuffer

import (
	context "context"
	fmt "fmt"
	proto "github.com/golang/protobuf/proto"
	grpc "google.golang.org/grpc"
	math "math"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.ProtoPackageIsVersion2 // please upgrade the proto package

type Node struct {
	X                    int32    `protobuf:"varint,1,opt,name=X,proto3" json:"X,omitempty"`
	Y                    int32    `protobuf:"varint,2,opt,name=Y,proto3" json:"Y,omitempty"`
	Player               int32    `protobuf:"varint,3,opt,name=Player,proto3" json:"Player,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *Node) Reset()         { *m = Node{} }
func (m *Node) String() string { return proto.CompactTextString(m) }
func (*Node) ProtoMessage()    {}
func (*Node) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{0}
}

func (m *Node) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_Node.Unmarshal(m, b)
}
func (m *Node) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_Node.Marshal(b, m, deterministic)
}
func (m *Node) XXX_Merge(src proto.Message) {
	xxx_messageInfo_Node.Merge(m, src)
}
func (m *Node) XXX_Size() int {
	return xxx_messageInfo_Node.Size(m)
}
func (m *Node) XXX_DiscardUnknown() {
	xxx_messageInfo_Node.DiscardUnknown(m)
}

var xxx_messageInfo_Node proto.InternalMessageInfo

func (m *Node) GetX() int32 {
	if m != nil {
		return m.X
	}
	return 0
}

func (m *Node) GetY() int32 {
	if m != nil {
		return m.Y
	}
	return 0
}

func (m *Node) GetPlayer() int32 {
	if m != nil {
		return m.Player
	}
	return 0
}

type ConfigRules struct {
	PlayerIndexIA               int32    `protobuf:"varint,1,opt,name=PlayerIndexIA,proto3" json:"PlayerIndexIA,omitempty"`
	IsActiveRuleFreeThree       bool     `protobuf:"varint,2,opt,name=IsActiveRuleFreeThree,proto3" json:"IsActiveRuleFreeThree,omitempty"`
	IsActiveRuleCapture         bool     `protobuf:"varint,3,opt,name=IsActiveRuleCapture,proto3" json:"IsActiveRuleCapture,omitempty"`
	IsActiveRuleAlignment       bool     `protobuf:"varint,4,opt,name=IsActiveRuleAlignment,proto3" json:"IsActiveRuleAlignment,omitempty"`
	IsActiveRuleWin             bool     `protobuf:"varint,5,opt,name=IsActiveRuleWin,proto3" json:"IsActiveRuleWin,omitempty"`
	IsActiveRuleBlock           bool     `protobuf:"varint,6,opt,name=IsActiveRuleBlock,proto3" json:"IsActiveRuleBlock,omitempty"`
	IsActiveRuleProbableCapture bool     `protobuf:"varint,7,opt,name=IsActiveRuleProbableCapture,proto3" json:"IsActiveRuleProbableCapture,omitempty"`
	IsActiveRuleAmbientSearch   bool     `protobuf:"varint,8,opt,name=IsActiveRuleAmbientSearch,proto3" json:"IsActiveRuleAmbientSearch,omitempty"`
	IsActiveHelperPlayer        bool     `protobuf:"varint,9,opt,name=IsActiveHelperPlayer,proto3" json:"IsActiveHelperPlayer,omitempty"`
	DepthIA                     int32    `protobuf:"varint,10,opt,name=DepthIA,proto3" json:"DepthIA,omitempty"`
	XXX_NoUnkeyedLiteral        struct{} `json:"-"`
	XXX_unrecognized            []byte   `json:"-"`
	XXX_sizecache               int32    `json:"-"`
}

func (m *ConfigRules) Reset()         { *m = ConfigRules{} }
func (m *ConfigRules) String() string { return proto.CompactTextString(m) }
func (*ConfigRules) ProtoMessage()    {}
func (*ConfigRules) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{1}
}

func (m *ConfigRules) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_ConfigRules.Unmarshal(m, b)
}
func (m *ConfigRules) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_ConfigRules.Marshal(b, m, deterministic)
}
func (m *ConfigRules) XXX_Merge(src proto.Message) {
	xxx_messageInfo_ConfigRules.Merge(m, src)
}
func (m *ConfigRules) XXX_Size() int {
	return xxx_messageInfo_ConfigRules.Size(m)
}
func (m *ConfigRules) XXX_DiscardUnknown() {
	xxx_messageInfo_ConfigRules.DiscardUnknown(m)
}

var xxx_messageInfo_ConfigRules proto.InternalMessageInfo

func (m *ConfigRules) GetPlayerIndexIA() int32 {
	if m != nil {
		return m.PlayerIndexIA
	}
	return 0
}

func (m *ConfigRules) GetIsActiveRuleFreeThree() bool {
	if m != nil {
		return m.IsActiveRuleFreeThree
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleCapture() bool {
	if m != nil {
		return m.IsActiveRuleCapture
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleAlignment() bool {
	if m != nil {
		return m.IsActiveRuleAlignment
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleWin() bool {
	if m != nil {
		return m.IsActiveRuleWin
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleBlock() bool {
	if m != nil {
		return m.IsActiveRuleBlock
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleProbableCapture() bool {
	if m != nil {
		return m.IsActiveRuleProbableCapture
	}
	return false
}

func (m *ConfigRules) GetIsActiveRuleAmbientSearch() bool {
	if m != nil {
		return m.IsActiveRuleAmbientSearch
	}
	return false
}

func (m *ConfigRules) GetIsActiveHelperPlayer() bool {
	if m != nil {
		return m.IsActiveHelperPlayer
	}
	return false
}

func (m *ConfigRules) GetDepthIA() int32 {
	if m != nil {
		return m.DepthIA
	}
	return 0
}

type CDGameRequest struct {
	GameID               string       `protobuf:"bytes,1,opt,name=GameID,proto3" json:"GameID,omitempty"`
	Rules                *ConfigRules `protobuf:"bytes,2,opt,name=Rules,proto3" json:"Rules,omitempty"`
	Delete               bool         `protobuf:"varint,3,opt,name=Delete,proto3" json:"Delete,omitempty"`
	XXX_NoUnkeyedLiteral struct{}     `json:"-"`
	XXX_unrecognized     []byte       `json:"-"`
	XXX_sizecache        int32        `json:"-"`
}

func (m *CDGameRequest) Reset()         { *m = CDGameRequest{} }
func (m *CDGameRequest) String() string { return proto.CompactTextString(m) }
func (*CDGameRequest) ProtoMessage()    {}
func (*CDGameRequest) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{2}
}

func (m *CDGameRequest) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_CDGameRequest.Unmarshal(m, b)
}
func (m *CDGameRequest) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_CDGameRequest.Marshal(b, m, deterministic)
}
func (m *CDGameRequest) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CDGameRequest.Merge(m, src)
}
func (m *CDGameRequest) XXX_Size() int {
	return xxx_messageInfo_CDGameRequest.Size(m)
}
func (m *CDGameRequest) XXX_DiscardUnknown() {
	xxx_messageInfo_CDGameRequest.DiscardUnknown(m)
}

var xxx_messageInfo_CDGameRequest proto.InternalMessageInfo

func (m *CDGameRequest) GetGameID() string {
	if m != nil {
		return m.GameID
	}
	return ""
}

func (m *CDGameRequest) GetRules() *ConfigRules {
	if m != nil {
		return m.Rules
	}
	return nil
}

func (m *CDGameRequest) GetDelete() bool {
	if m != nil {
		return m.Delete
	}
	return false
}

type CheckRulesResponse struct {
	IsPossible           bool     `protobuf:"varint,1,opt,name=IsPossible,proto3" json:"IsPossible,omitempty"`
	Captured             []*Node  `protobuf:"bytes,2,rep,name=Captured,proto3" json:"Captured,omitempty"`
	NbStonedCaptured     int32    `protobuf:"varint,3,opt,name=NbStonedCaptured,proto3" json:"NbStonedCaptured,omitempty"`
	PartyFinish          bool     `protobuf:"varint,4,opt,name=PartyFinish,proto3" json:"PartyFinish,omitempty"`
	IsWin                int32    `protobuf:"varint,5,opt,name=IsWin,proto3" json:"IsWin,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *CheckRulesResponse) Reset()         { *m = CheckRulesResponse{} }
func (m *CheckRulesResponse) String() string { return proto.CompactTextString(m) }
func (*CheckRulesResponse) ProtoMessage()    {}
func (*CheckRulesResponse) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{3}
}

func (m *CheckRulesResponse) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_CheckRulesResponse.Unmarshal(m, b)
}
func (m *CheckRulesResponse) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_CheckRulesResponse.Marshal(b, m, deterministic)
}
func (m *CheckRulesResponse) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CheckRulesResponse.Merge(m, src)
}
func (m *CheckRulesResponse) XXX_Size() int {
	return xxx_messageInfo_CheckRulesResponse.Size(m)
}
func (m *CheckRulesResponse) XXX_DiscardUnknown() {
	xxx_messageInfo_CheckRulesResponse.DiscardUnknown(m)
}

var xxx_messageInfo_CheckRulesResponse proto.InternalMessageInfo

func (m *CheckRulesResponse) GetIsPossible() bool {
	if m != nil {
		return m.IsPossible
	}
	return false
}

func (m *CheckRulesResponse) GetCaptured() []*Node {
	if m != nil {
		return m.Captured
	}
	return nil
}

func (m *CheckRulesResponse) GetNbStonedCaptured() int32 {
	if m != nil {
		return m.NbStonedCaptured
	}
	return 0
}

func (m *CheckRulesResponse) GetPartyFinish() bool {
	if m != nil {
		return m.PartyFinish
	}
	return false
}

func (m *CheckRulesResponse) GetIsWin() int32 {
	if m != nil {
		return m.IsWin
	}
	return 0
}

type CDGameResponse struct {
	IsSuccess            bool     `protobuf:"varint,1,opt,name=IsSuccess,proto3" json:"IsSuccess,omitempty"`
	Message              string   `protobuf:"bytes,2,opt,name=Message,proto3" json:"Message,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *CDGameResponse) Reset()         { *m = CDGameResponse{} }
func (m *CDGameResponse) String() string { return proto.CompactTextString(m) }
func (*CDGameResponse) ProtoMessage()    {}
func (*CDGameResponse) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{4}
}

func (m *CDGameResponse) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_CDGameResponse.Unmarshal(m, b)
}
func (m *CDGameResponse) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_CDGameResponse.Marshal(b, m, deterministic)
}
func (m *CDGameResponse) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CDGameResponse.Merge(m, src)
}
func (m *CDGameResponse) XXX_Size() int {
	return xxx_messageInfo_CDGameResponse.Size(m)
}
func (m *CDGameResponse) XXX_DiscardUnknown() {
	xxx_messageInfo_CDGameResponse.DiscardUnknown(m)
}

var xxx_messageInfo_CDGameResponse proto.InternalMessageInfo

func (m *CDGameResponse) GetIsSuccess() bool {
	if m != nil {
		return m.IsSuccess
	}
	return false
}

func (m *CDGameResponse) GetMessage() string {
	if m != nil {
		return m.Message
	}
	return ""
}

type StonePlayed struct {
	CurrentPlayerMove    *Node    `protobuf:"bytes,1,opt,name=CurrentPlayerMove,proto3" json:"CurrentPlayerMove,omitempty"`
	GameID               string   `protobuf:"bytes,2,opt,name=GameID,proto3" json:"GameID,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *StonePlayed) Reset()         { *m = StonePlayed{} }
func (m *StonePlayed) String() string { return proto.CompactTextString(m) }
func (*StonePlayed) ProtoMessage()    {}
func (*StonePlayed) Descriptor() ([]byte, []int) {
	return fileDescriptor_1e21993b51421452, []int{5}
}

func (m *StonePlayed) XXX_Unmarshal(b []byte) error {
	return xxx_messageInfo_StonePlayed.Unmarshal(m, b)
}
func (m *StonePlayed) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	return xxx_messageInfo_StonePlayed.Marshal(b, m, deterministic)
}
func (m *StonePlayed) XXX_Merge(src proto.Message) {
	xxx_messageInfo_StonePlayed.Merge(m, src)
}
func (m *StonePlayed) XXX_Size() int {
	return xxx_messageInfo_StonePlayed.Size(m)
}
func (m *StonePlayed) XXX_DiscardUnknown() {
	xxx_messageInfo_StonePlayed.DiscardUnknown(m)
}

var xxx_messageInfo_StonePlayed proto.InternalMessageInfo

func (m *StonePlayed) GetCurrentPlayerMove() *Node {
	if m != nil {
		return m.CurrentPlayerMove
	}
	return nil
}

func (m *StonePlayed) GetGameID() string {
	if m != nil {
		return m.GameID
	}
	return ""
}

func init() {
	proto.RegisterType((*Node)(nil), "gomokuBuffer.Node")
	proto.RegisterType((*ConfigRules)(nil), "gomokuBuffer.ConfigRules")
	proto.RegisterType((*CDGameRequest)(nil), "gomokuBuffer.CDGameRequest")
	proto.RegisterType((*CheckRulesResponse)(nil), "gomokuBuffer.CheckRulesResponse")
	proto.RegisterType((*CDGameResponse)(nil), "gomokuBuffer.CDGameResponse")
	proto.RegisterType((*StonePlayed)(nil), "gomokuBuffer.StonePlayed")
}

func init() { proto.RegisterFile("buffer.proto", fileDescriptor_1e21993b51421452) }

var fileDescriptor_1e21993b51421452 = []byte{
	// 583 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x9c, 0x54, 0x4d, 0x6f, 0xd3, 0x40,
	0x10, 0x6d, 0xd2, 0x26, 0x4d, 0x26, 0x2d, 0xd0, 0xa1, 0x20, 0xf7, 0x43, 0x28, 0xb2, 0x38, 0x54,
	0x08, 0x05, 0x14, 0x38, 0x21, 0x0e, 0x49, 0x13, 0x4a, 0x2d, 0xd4, 0x2a, 0x72, 0x90, 0x68, 0x8f,
	0xfe, 0x98, 0x24, 0x56, 0x1c, 0xaf, 0xd9, 0xb5, 0x2b, 0xfa, 0x77, 0xf8, 0x35, 0xfc, 0x23, 0xae,
	0xc8, 0xbb, 0x76, 0xb2, 0xf9, 0x68, 0x0f, 0xdc, 0xf2, 0xde, 0x9b, 0xd9, 0x9d, 0xd9, 0xf7, 0x62,
	0xd8, 0x73, 0xd3, 0xd1, 0x88, 0x78, 0x2b, 0xe6, 0x2c, 0x61, 0xb8, 0x37, 0x66, 0x33, 0x36, 0x4d,
	0xcf, 0x25, 0x67, 0x7e, 0x82, 0x9d, 0x6b, 0xe6, 0x13, 0xee, 0x41, 0xe9, 0xc6, 0x28, 0x35, 0x4b,
	0x67, 0x15, 0xbb, 0x74, 0x93, 0xa1, 0x5b, 0xa3, 0xac, 0xd0, 0x2d, 0xbe, 0x84, 0xea, 0x20, 0x74,
	0xee, 0x89, 0x1b, 0xdb, 0x92, 0xca, 0x91, 0xf9, 0x77, 0x1b, 0x1a, 0x3d, 0x16, 0x8d, 0x82, 0xb1,
	0x9d, 0x86, 0x24, 0xf0, 0x35, 0xec, 0x2b, 0xc5, 0x8a, 0x7c, 0xfa, 0x65, 0x75, 0xf3, 0xf3, 0x96,
	0x49, 0xfc, 0x08, 0x2f, 0x2c, 0xd1, 0xf5, 0x92, 0xe0, 0x8e, 0xb2, 0xb6, 0x0b, 0x4e, 0xf4, 0x7d,
	0xc2, 0x89, 0xe4, 0x7d, 0x35, 0x7b, 0xb3, 0x88, 0xef, 0xe1, 0xb9, 0x2e, 0xf4, 0x9c, 0x38, 0x49,
	0x39, 0xc9, 0x81, 0x6a, 0xf6, 0x26, 0x69, 0xf5, 0x9e, 0x6e, 0x18, 0x8c, 0xa3, 0x19, 0x45, 0x89,
	0xb1, 0xb3, 0x7e, 0xcf, 0x5c, 0xc4, 0x33, 0x78, 0xaa, 0x0b, 0x3f, 0x82, 0xc8, 0xa8, 0xc8, 0xfa,
	0x55, 0x1a, 0xdf, 0xc2, 0x81, 0x4e, 0x9d, 0x87, 0xcc, 0x9b, 0x1a, 0x55, 0x59, 0xbb, 0x2e, 0x60,
	0x07, 0x4e, 0x74, 0x72, 0xc0, 0x99, 0xeb, 0xb8, 0x8b, 0x3d, 0x76, 0x65, 0xdf, 0x63, 0x25, 0xf8,
	0x19, 0x8e, 0x96, 0x46, 0x9e, 0xb9, 0x01, 0x45, 0xc9, 0x90, 0x1c, 0xee, 0x4d, 0x8c, 0x9a, 0xec,
	0x7f, 0xb8, 0x00, 0xdb, 0x70, 0x58, 0x88, 0x97, 0x14, 0xc6, 0xc4, 0x73, 0x47, 0xeb, 0xb2, 0x71,
	0xa3, 0x86, 0x06, 0xec, 0xf6, 0x29, 0x4e, 0x26, 0x56, 0xd7, 0x00, 0xe9, 0x64, 0x01, 0xcd, 0x18,
	0xf6, 0x7b, 0xfd, 0xaf, 0xce, 0x8c, 0x6c, 0xfa, 0x99, 0x92, 0x48, 0xb2, 0x88, 0x64, 0xd0, 0xea,
	0x4b, 0xcf, 0xeb, 0x76, 0x8e, 0xf0, 0x1d, 0x54, 0x64, 0x36, 0xa4, 0xb9, 0x8d, 0xf6, 0x51, 0x4b,
	0x0f, 0x5f, 0x4b, 0x0b, 0x8f, 0xad, 0xea, 0xb2, 0x83, 0xfa, 0x14, 0x52, 0x52, 0x58, 0x9b, 0x23,
	0xf3, 0x4f, 0x09, 0xb0, 0x37, 0x21, 0x6f, 0xaa, 0xaa, 0x49, 0xc4, 0x2c, 0x12, 0x84, 0xaf, 0x00,
	0x2c, 0x31, 0x60, 0x42, 0x04, 0x6e, 0x48, 0xf2, 0xee, 0x9a, 0xad, 0x31, 0xd8, 0x82, 0x5a, 0xfe,
	0x7e, 0xbe, 0x51, 0x6e, 0x6e, 0x9f, 0x35, 0xda, 0xb8, 0x3c, 0x42, 0x16, 0x7e, 0x7b, 0x5e, 0x83,
	0x6f, 0xe0, 0xd9, 0xb5, 0x3b, 0x4c, 0x58, 0x44, 0xfe, 0xbc, 0x4f, 0x85, 0x7e, 0x8d, 0xc7, 0x26,
	0x34, 0x06, 0x0e, 0x4f, 0xee, 0x2f, 0x82, 0x28, 0x10, 0x93, 0x3c, 0x56, 0x3a, 0x85, 0x87, 0x50,
	0xb1, 0x44, 0x11, 0xa1, 0x8a, 0xad, 0x80, 0x79, 0x09, 0x4f, 0x8a, 0xc7, 0xcb, 0xb7, 0x38, 0x85,
	0xba, 0x25, 0x86, 0xa9, 0xe7, 0x91, 0x10, 0xf9, 0x12, 0x0b, 0x22, 0xb3, 0xe1, 0x8a, 0x84, 0x70,
	0xc6, 0xea, 0x2f, 0x52, 0xb7, 0x0b, 0x68, 0x8e, 0xa1, 0x21, 0x67, 0x92, 0x7e, 0xf9, 0xd8, 0x81,
	0x83, 0x5e, 0xca, 0x39, 0x45, 0x89, 0x32, 0xf0, 0x8a, 0xdd, 0xa9, 0x37, 0xd9, 0xbc, 0xf5, 0x7a,
	0xb1, 0x66, 0x63, 0x59, 0xb7, 0xb1, 0xfd, 0xbb, 0x0c, 0x3b, 0xd9, 0x4f, 0xfc, 0x02, 0x55, 0x35,
	0x3b, 0x9e, 0xac, 0x58, 0xa9, 0xc7, 0xe1, 0xf8, 0x74, 0xb3, 0xa8, 0xd6, 0x35, 0xb7, 0xb0, 0x93,
	0x7f, 0x51, 0x7c, 0x5c, 0x49, 0x84, 0xb6, 0xce, 0xf1, 0xc3, 0x92, 0xb9, 0x85, 0x7d, 0x00, 0xf5,
	0x3b, 0x4b, 0xec, 0x7f, 0x9f, 0xf2, 0x0d, 0x60, 0x11, 0xaa, 0xc7, 0x4e, 0x69, 0xae, 0x2c, 0xb4,
	0x96, 0x44, 0x73, 0xcb, 0xad, 0xca, 0xef, 0xeb, 0x87, 0x7f, 0x01, 0x00, 0x00, 0xff, 0xff, 0xce,
	0x7f, 0xca, 0xe1, 0x6f, 0x05, 0x00, 0x00,
}

// Reference imports to suppress errors if they are not otherwise used.
var _ context.Context
var _ grpc.ClientConn

// This is a compile-time assertion to ensure that this generated file
// is compatible with the grpc package it is being compiled against.
const _ = grpc.SupportPackageIsVersion4

// GameClient is the client API for Game service.
//
// For semantics around ctx use and closing/ending streaming RPCs, please refer to https://godoc.org/google.golang.org/grpc#ClientConn.NewStream.
type GameClient interface {
	CDGame(ctx context.Context, in *CDGameRequest, opts ...grpc.CallOption) (*CDGameResponse, error)
	Played(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*StonePlayed, error)
	PlayedHelp(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*StonePlayed, error)
	CheckRules(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*CheckRulesResponse, error)
}

type gameClient struct {
	cc *grpc.ClientConn
}

func NewGameClient(cc *grpc.ClientConn) GameClient {
	return &gameClient{cc}
}

func (c *gameClient) CDGame(ctx context.Context, in *CDGameRequest, opts ...grpc.CallOption) (*CDGameResponse, error) {
	out := new(CDGameResponse)
	err := c.cc.Invoke(ctx, "/gomokuBuffer.Game/CDGame", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *gameClient) Played(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*StonePlayed, error) {
	out := new(StonePlayed)
	err := c.cc.Invoke(ctx, "/gomokuBuffer.Game/Played", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *gameClient) PlayedHelp(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*StonePlayed, error) {
	out := new(StonePlayed)
	err := c.cc.Invoke(ctx, "/gomokuBuffer.Game/PlayedHelp", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

func (c *gameClient) CheckRules(ctx context.Context, in *StonePlayed, opts ...grpc.CallOption) (*CheckRulesResponse, error) {
	out := new(CheckRulesResponse)
	err := c.cc.Invoke(ctx, "/gomokuBuffer.Game/CheckRules", in, out, opts...)
	if err != nil {
		return nil, err
	}
	return out, nil
}

// GameServer is the server API for Game service.
type GameServer interface {
	CDGame(context.Context, *CDGameRequest) (*CDGameResponse, error)
	Played(context.Context, *StonePlayed) (*StonePlayed, error)
	PlayedHelp(context.Context, *StonePlayed) (*StonePlayed, error)
	CheckRules(context.Context, *StonePlayed) (*CheckRulesResponse, error)
}

func RegisterGameServer(s *grpc.Server, srv GameServer) {
	s.RegisterService(&_Game_serviceDesc, srv)
}

func _Game_CDGame_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(CDGameRequest)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(GameServer).CDGame(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/gomokuBuffer.Game/CDGame",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(GameServer).CDGame(ctx, req.(*CDGameRequest))
	}
	return interceptor(ctx, in, info, handler)
}

func _Game_Played_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(StonePlayed)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(GameServer).Played(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/gomokuBuffer.Game/Played",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(GameServer).Played(ctx, req.(*StonePlayed))
	}
	return interceptor(ctx, in, info, handler)
}

func _Game_PlayedHelp_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(StonePlayed)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(GameServer).PlayedHelp(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/gomokuBuffer.Game/PlayedHelp",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(GameServer).PlayedHelp(ctx, req.(*StonePlayed))
	}
	return interceptor(ctx, in, info, handler)
}

func _Game_CheckRules_Handler(srv interface{}, ctx context.Context, dec func(interface{}) error, interceptor grpc.UnaryServerInterceptor) (interface{}, error) {
	in := new(StonePlayed)
	if err := dec(in); err != nil {
		return nil, err
	}
	if interceptor == nil {
		return srv.(GameServer).CheckRules(ctx, in)
	}
	info := &grpc.UnaryServerInfo{
		Server:     srv,
		FullMethod: "/gomokuBuffer.Game/CheckRules",
	}
	handler := func(ctx context.Context, req interface{}) (interface{}, error) {
		return srv.(GameServer).CheckRules(ctx, req.(*StonePlayed))
	}
	return interceptor(ctx, in, info, handler)
}

var _Game_serviceDesc = grpc.ServiceDesc{
	ServiceName: "gomokuBuffer.Game",
	HandlerType: (*GameServer)(nil),
	Methods: []grpc.MethodDesc{
		{
			MethodName: "CDGame",
			Handler:    _Game_CDGame_Handler,
		},
		{
			MethodName: "Played",
			Handler:    _Game_Played_Handler,
		},
		{
			MethodName: "PlayedHelp",
			Handler:    _Game_PlayedHelp_Handler,
		},
		{
			MethodName: "CheckRules",
			Handler:    _Game_CheckRules_Handler,
		},
	},
	Streams:  []grpc.StreamDesc{},
	Metadata: "buffer.proto",
}